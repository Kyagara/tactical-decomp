#!/usr/bin/env python3
"""Regenerate the 58 PSYQ stubs splat does not emit (build repair).

Splat (0.50.0) with the current config merges 58 PSYQ library functions
into neighbours and emits no .s for them, yet src/main.c and
src/main_3.c reference them via INCLUDE_PSYQ, so a fresh
`make extract` + `make split` leaves `make build` failing with 58
"can't open ... .s" errors. The stubs are byte-exact `.word` dumps from
the baserom (sizes = vram gaps over the complete src+applied_names
symbol layout, including human-named C defs and D_*/pad_* so data
thunks are not swallowed).

Run from the repo root after `make split` (or any `make clean`, which
deletes rom/extracted/asm) and before `make build`:
    tools/.venv/bin/python tools/scripts/regen_psyq_stubs.py
`make build` then links cleanly. The generated files live under
rom/extracted/asm/nonmatchings/ (git-ignored) and survive later
incremental splits (prune keeps them: their INCLUDE_PSYQ/RODATA tokens
exist). A future `make clean` wipes them; just re-run this script
(the Makefile `split` target runs it automatically).
Long-term fix: teach splat to split these (symbol_addrs entries) so
this script becomes unnecessary. NOTE: D_8001008C is deliberately NOT
in symbol_addrs: splat emits a truncated relocatable jumptable
(8 `.word .L...` with undefined locals); the hand absolute version
(31 `.word 0x...`) below is byte-exact and required for `make compare`.
"""
import re, pathlib, struct
baserom = open('rom/extracted/baserom/SCUS_942.21','rb').read()
human_vram={}
for line in open('config/applied_names.txt'):
    m=re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+)',line)
    if m: human_vram[m.group(1)]=int(m.group(2),16)
for line in open('config/symbol_addrs.txt'):
    m=re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+)',line)
    if m and m.group(1) not in human_vram:
        human_vram[m.group(1)]=int(m.group(2),16)
def vram_of(name):
    if name in human_vram: return human_vram[name]
    if '_' in name:
        try:
            hexpart=name.split('_',1)[1]
            if len(hexpart)>=8 and all(c in '0123456789ABCDEFabcdef' for c in hexpart[:8]):
                return int(hexpart[:8],16)
        except: pass
    return None
tokens=[]
for seg in ['main','main_2','main_3','main_4','main_5']:
    ctext=open(f'src/{seg}.c').read()
    for m in re.finditer(r'INCLUDE_(?:ASM|PSYQ|RODATA)\([^,]+,\s*(\w+)', ctext):
        name=m.group(1)
        vram=vram_of(name)
        if vram is None: continue
        tokens.append((vram,name))
    clines = ctext.splitlines()
    for li, line in enumerate(clines):
        m = re.match(r'^(?:[\w][\w\s]*?\s+)?\*?\s*(\w+)\s*\([^;{}]*\)\s*\{', line)
        if m is None:
            # Allman-brace definition: signature on this line, `{` on next
            m2 = re.match(r'^(?:[\w][\w\s]*?\s+)?\*?\s*(\w+)\s*\([^;{}]*\)\s*$', line)
            if m2 is not None and li + 1 < len(clines) and clines[li + 1].strip() == '{':
                m = m2
        if not m: continue
        name = m.group(1)
        if name in ('if','for','while','switch','do','return'): continue
        if any(t[1]==name for t in tokens): continue
        vram=vram_of(name)
        if vram is None: continue
        tokens.append((vram,name))
tokens.sort()
gaps={}
for i,(v,n) in enumerate(tokens):
    for j in range(i+1,len(tokens)):
        if tokens[j][0]>v:
            if tokens[j][0]-v < 0x5000:
                gaps[n]=tokens[j][0]-v
            break
def foff_of(vram):
    if 0x80010000 <= vram < 0x80022114:
        return vram-0x80010000+0x800
    elif 0x80022114 <= vram < 0x80028AF4:
        return vram-0x80022114+0x12914
    elif 0x80040934 <= vram < 0x8004593C:
        return vram-0x80040934+0x31134
    elif 0x80059854 <= vram < 0x80060000:
        return vram-0x80059854+0x4A054
    return None
for seg in ['main','main_2','main_3']:
    d=pathlib.Path(f'rom/extracted/asm/nonmatchings/{seg}')
    d.mkdir(parents=True, exist_ok=True)
    ctext=open(f'src/{seg}.c').read()
    for m in re.finditer(r'INCLUDE_PSYQ\([^,]+,\s*(\w+)', ctext):
        name=m.group(1)
        p=d/(name+'.s')
        if p.exists() and 'Regenerated PSYQ' in p.read_text()[:500]:
            pass  # refresh below (sizes may have changed after src edits)
        elif p.exists():
            continue  # splat-emitted stub (game code or healthy PSYQ); leave alone
        vram=vram_of(name)
        size=gaps.get(name)
        foff=foff_of(vram)
        if vram is None or size is None or foff is None:
            print(f'skip {seg}/{name}'); continue
        data=baserom[foff:foff+size]
        words=struct.unpack(f'<{len(data)//4}I', data[:len(data)//4*4])
        with open(p,'w') as f:
            f.write(f"/* Regenerated PSYQ stub (bytes from baserom foff 0x{foff:X}, size 0x{size:X}) */\n")
            f.write(f"nonmatching {name}, 0x{size:X}\n\n")
            f.write(f"glabel {name}\n")
            for w in words:
                f.write(f"    .word 0x{w:08X}\n")
            f.write(f"endlabel {name}\n")
        print(f'wrote {seg}/{name} 0x{size:X}')
# Hand absolute jumptable D_8001008C (31 words from baserom 0x88C; splat
# emits a truncated 8-word relocatable version with undefined .L locals).
if 'D_8001008C' in open('src/main.c').read():
    p=pathlib.Path('rom/extracted/asm/nonmatchings/main/D_8001008C.s')
    foff, vram, size = 0x88C, 0x8001008C, 124
    data=baserom[foff:foff+size]
    words=struct.unpack(f'<{size//4}I', data)
    with open(p,'w') as f:
        f.write(".section .rodata\n\n.align 2\nnonmatching D_8001008C\n\ndlabel D_8001008C\n")
        for i,w in enumerate(words):
            f.write(f"    /* {foff+i*4:X} {vram+i*4:08X} {w:08X} */ .word 0x{w:08X}\n")
        f.write("enddlabel D_8001008C\n")
    print('wrote main/D_8001008C 0x7C')
print('done')
