# MIPS I Assembly Reference for the PlayStation (PS1/PSX)

Condensed MIPS instruction reference for the PSX. The primary
source is the **Final Fantasy Hacktics Wiki** pages; psx-spx and the
official MIPS manual are cited where hardware-accurate
detail (opcode encoding, delays) is needed. See `PSX_REFERENCE.md` §2 for how
this ties into the decomp pipeline.

## Sources

| Source | Kind | Where |
| --- | --- | --- |
| Final Fantasy Hacktics Wiki - R3000 instruction set | base MIPS I ISA, registers, conventions | [online](https://ffhacktics.com/wiki/R3000_instruction_set) |
| Final Fantasy Hacktics Wiki - PSX instruction set | full mnemonic table incl. COP2/GTE | [online](https://ffhacktics.com/wiki/PSX_instruction_set) |
| psx-spx - CPU Specifications | authoritative opcode encoding, delay rules, COP0 | [online](https://psx-spx.consoledev.net/cpuspecifications/) |
| Nocash - PSXSPX GTE Overview | GTE command encoding, cycles, register semantics | [online](https://problemkaputt.de/psxspx-gte-overview.htm) |
| MIPS R3000 Software Reference Manual (IDT/MIPS) | canonical ISA manual | [PDF](https://student.cs.uwaterloo.ca/~cs350/common/r3000-manual.pdf) |

> **psxfin `jalr` warning (FFH):** psxfin's disassembler emits `jalr`'s two
> arguments in the **wrong order**. The FFH wiki and tools use `jalr rs,rd`
> (jump to `rs`, link into `rd`) for consistency with psxfin; the MIPS
> specification writes `jalr rd,rs`. In `rom/extracted/asm/` the canonical
> `jalr $ra,$tN` / `jalr $s` form appears.

---

## Registers

32 registers, each 32-bit. Every register is usable in any instruction that
takes a register operand, but the ABI gives them roles:

| # | ABI name | Used for |
| --- | --- | --- |
| r0 | `zero` | Always 0; writing does nothing |
| r1 | `at` | Assembler temporary (destroyed by some pseudo-instructions) |
| r2–r3 | `v0`–`v1` | Subroutine return values; may be clobbered |
| r4–r7 | `a0`–`a3` | First four arguments; may be clobbered |
| r8–r15 | `t0`–`t7` | Temporaries; may be used without saving |
| r16–r23 | `s0`–`s7` | Callee-saved: save + restore before returning |
| r24–r25 | `t8`–`t9` | Temporaries; may be used without saving |
| r26–r27 | `k0`–`k1` | Reserved for interrupt/trap handler - do not modify |
| r28 | `gp` | Global pointer - do not modify |
| r29 | `sp` | Stack pointer (points at first free address; grows down) |
| r30 | `s8`/`fp` | 9th register variable / frame pointer |
| r31 | `ra` | Return address; `jal` writes it implicitly |

**Callee-saved (must restore before returning):** r16–r23 (`s0–s7`), and
r28–r31 by convention. **Caller-saved / may clobber:** r2–r7, r8–r15, r24–r25.

**Special registers** (not in the GPR file): `HI` and `LO` hold the 64-bit
multiply result and the divide quotient/remainder (see `mult`/`div`), read via
`mfhi`/`mflo`.

---

## Notation

- `$t` target register, `$s` source register, `$d` destination register.
- `C` = 16-bit constant (not a register).
- `shamt` = shift amount, 5 bits.

**Memory alignment:** word (32-bit) loads/stores require addresses divisible by
4 (hex ends `0,4,8,C`); halfword (16-bit) require divisible by 2 (`0,2,4,6,8,A,C,E`);
byte has no requirement. Misaligned word access raises an exception.

---

## Base MIPS I instruction set

Grouped by function. Each row carries a short "how it works" note.

### Arithmetic

| Instr | Syntax | Effect / note |
| --- | --- | --- |
| `add` | `add $d,$s,$t` | `d = s + t` (traps on overflow) |
| `addu` | `addu $d,$s,$t` | `d = s + t`. **The default C-compiler add**; "unsigned" = don't set the overflow flag - fine for signed too. |
| `sub` | `sub $d,$s,$t` | `d = s - t` (traps on overflow) |
| `subu` | `subu $d,$s,$t` | `d = s - t` (no overflow trap) |
| `addi` | `addi $t,$s,C` | `t = s + sign-extended C` (traps on overflow) |
| `addiu` | `addiu $t,$s,C` | `t = s + sign-extended C` (no overflow trap; compiler default for stack/pointer math) |
| `mult` | `mult $s,$t` | 64-bit product of `s*t`; **LO = low 32 bits, HI = high 32 bits**. Read with `mflo`/`mfhi`. Slow; the compiler instead uses shift+add for constants, or `mult`+`mfhi` for ×fractions. |
| `multu` | `multu $s,$t` | Same, but operands treated as unsigned. |
| `div` | `div $s,$t` | **LO = quotient `s/t`, HI = remainder `s%t`** (signed). |
| `divu` | `divu $s,$t` | Same, unsigned. |
| `mfhi` | `mfhi $d` | `d = HI` (high multiply / division remainder). |
| `mflo` | `mflo $d` | `d = LO` (low multiply / division quotient). |

### Memory

| Instr | Syntax | Effect / note |
| --- | --- | --- |
| `lw` | `lw $t,C($s)` | `t = mem32[s+C]` |
| `lh` | `lh $t,C($s)` | `t = sign-extended mem16[s+C]` |
| `lhu` | `lhu $t,C($s)` | `t = zero-extended mem16[s+C]` |
| `lb` | `lb $t,C($s)` | `t = sign-extended mem8[s+C]` |
| `lbu` | `lbu $t,C($s)` | `t = zero-extended mem8[s+C]` |
| `lwl` | `lwl $t,C($s)` | Load-word-left: loads the **first/last** part of an unaligned word (see note). |
| `lwr` | `lwr $t,C($s)` | Load-word-right: the other half. Pair `lwl`/`lwr` to read an unaligned 4-byte word. |
| `sw` | `sw $t,C($s)` | `mem32[s+C] = t` |
| `sh` | `sh $t,C($s)` | `mem16[s+C] = t & 0xFFFF` |
| `sb` | `sb $t,C($s)` | `mem8[s+C] = t & 0xFF` |
| `lui` | `lui $t,C` | `t = C << 16`. Not a memory access, but always used with `%hi/%lo` to build 32-bit addresses (see `PSX_REFERENCE.md` §2). |

### Comparison (set 1 if true, 0 if false)

| Instr | Syntax | Effect |
| --- | --- | --- |
| `slt` | `slt $d,$s,$t` | `d = (s < t)` signed |
| `slti` | `slti $t,$s,C` | `t = (s < sign-extended C)` signed |
| `sltiu` | `sltiu $t,$s,C` | `t = (s < C)` unsigned compare |
| `sltu` | `sltu $d,$s,$t` | `d = (s < t)` unsigned |

### Bitwise

| Instr | Syntax | Effect |
| --- | --- | --- |
| `and` | `and $d,$s,$t` | `d = s & t` |
| `andi` | `andi $t,$s,C` | `t = s & C` (zero-extended) |
| `or` | `or $d,$s,$t` | `d = s \| t` |
| `ori` | `ori $t,$s,C` | `t = s \| C` (zero-extended) |
| `xor` | `xor $d,$s,$t` | `d = s ^ t` |
| `xori` | `xori $t,$s,C` | `t = s ^ C` |
| `nor` | `nor $d,$s,$t` | `d = ~(s \| t)` |

### Shift

| Instr | Syntax | Effect |
| --- | --- | --- |
| `sll` | `sll $d,$t,shamt` | `d = t << shamt`, zero-filled |
| `srl` | `srl $d,$t,shamt` | `d = t >> shamt` logical (zero-filled) |
| `sra` | `sra $d,$t,shamt` | `d = t >> shamt` arithmetic (sign bit duplicated) |
| `sllv` | `sllv $d,$t,$s` | `d = t << s` (shift amount in a register) |
| `srlv` | `srlv $d,$t,$s` | `d = t >> s` logical variable |
| `srav` | `srav $d,$t,$s` | `d = t >> s` arithmetic variable |

### Control

| Instr | Syntax | Effect / note |
| --- | --- | --- |
| `beq` | `beq $s,$t,C` | `if (s == t) pc += C` (offset from PC+4) |
| `bne` | `bne $s,$t,C` | `if (s != t) pc += C` |
| `bgez` | `bgez $s,C` | `if (s >= 0) pc += C` |
| `bltz` | `bltz $s,C` | `if (s < 0) pc += C` |
| `bgtz` | `bgtz $s,C` | `if (s > 0) pc += C` |
| `blez` | `blez $s,C` | `if (s <= 0) pc += C` |
| `bgezal` | `bgezal $s,C` | `if (s >= 0) { ra = pc+4; pc += C }` - link variant |
| `bltzal` | `bltzal $s,C` | `if (s < 0) { ra = pc+4; pc += C }` - link variant |
| `j` | `j C` | `pc = 26-bit target` (absolute, upper bits from PC) |
| `jr` | `jr $s` | `pc = s` (return from subroutine) |
| `jal` | `jal C` | **stores PC+8 into `ra`, then jumps to `C`** - the +8 skips the delay slot so a called subroutine returns correctly. |
| `jalr` | `jalr $s[, $d]` | Jump to `s`, link PC+8 into `d` (default `ra`). **psxfin prints the 2-arg form as `jalr $s,$d`; the MIPS spec is `jalr $d,$s`.** |

---

## System / coprocessor instructions (incl. COP2 = GTE)

| Instr | Syntax | Effect / note |
| --- | --- | --- |
| `syscall` | `syscall` | System call exception (code in the immediate field). PSX kernels: `0`=noop, `1`=EnterCriticalSection, `2`=ExitCriticalSection, `3`=ChangeThreadSubFunction(addr in r5); others do nothing. |
| `break` | `break immed.` | Breakpoint exception (code 9). Recognized codes like `1c00` (divide-by-zero) and `1800` (division overflow) may be invoked by software. |
| `rfe` | `rfe` | Return-From-Exception (the only COP0 command the PSX supports). |
| `mfc0` / `mtc0` | `mfc0 rd,$t,0` / `mtc0 $t,rs,0` | Move from/to COP0 register. |
| `cfc0` / `ctc0` | `cfc0 rd,$t,0` / `ctc0 rd,$t,0` | Copy from/to COP0 control register. |

**COP2 (GTE)** - the geometry coprocessor. splat disassembles these; **m2c
struggles with them - flag GTE functions rather than guessing** (see
`AGENTS.md` and `PSX_REFERENCE.md` §1.1). Full cycle counts and register
semantics are in psx-spx / the Nocash GTE overview.

| Instr | Meaning (short) |
| --- | --- |
| `rtps` | Perspective transformation, single vector (`vxy0,vz0`) |
| `rtpt` | Perspective transformation, triple vector |
| `nclip` | Normal clipping; sign of result = polygon winding (front/back face) |
| `avsz3` | Average of three Z values (triangles) → `OTZ = (ZSF3*(SZ1+SZ2+SZ3)) >> 12` |
| `avsz4` | Average of four Z values (quads) → `OTZ` |
| `mvmva` | Multiply vector by matrix and add (`IR = v × mx + cv`) |
| `op` | Cross (outer) product of 2 vectors (`IR × RT…`) |
| `gpf` | General-purpose interpolation (`IR = IR*IR0 + O`) |
| `gpl` | General interpolation with base (`IR = IR*IR0 + A`) |
| `ncs` / `nct` | Normal color, single / triple |
| `nccs` / `ncct` | Normal color-color, single / triple vector |
| `ncds` / `ncdt` | Normal color depth-cue, single / triple |
| `dcpl` | Depth-cue color light |
| `dpcs` / `dpct` | Depth cueing, single / triple |
| `intpl` | Interpolate vector and far color |
| `sqr` | Square vector |
| `cc` / `cdp` | Color color / color depth-que |
| `lwc2` / `swc2` | Load/store word to/from GTE data register (`gtedr`) |
| `mfc2` / `mtc2` | Move from/to GTE data register |
| `cfc2` / `ctc2` | Copy from/to GTE control register (`gtecr`) |
| `copz` | Raw coprocessor opcode (`cop 0/2 immed.`) |

---

## PS1-specific behavior to remember

- **Branch delay slot:** the instruction **immediately after** a branch/jump
  (`beq`, `bne`, `j`, `jal`, `jr`, `jalr`, …) **always executes**, whether or
  not the branch is taken. This shapes every matched function's schedule - GCC
  2.6 fills these slots with real work (`AGENTS.md` "Compiler pin").
- **Load delay:** the R3000 has a load delay - a load followed immediately by a
  use of its destination needs a `nop` (GCC fills it). Loads from COP0/COP2
  registers can have a 1-instruction delay too.
- **Store delay:** writing COP2 registers has a ~2–3 clock-cycle delay (so the
  result is not immediately readable); `IRGB` takes 3 cycles because it also
  affects IR1–IR3.
- **`jalr` order:** psxfin emits `jalr $s,$d`; the MIPS spec is `jalr $d,$s`.
  FFT's tools follow psxfin.
- **Address building:** 32-bit addresses are `lui $at,%hi(sym)` + `addiu
  $at,%lo(sym)`; splat shows this as `lui $v0,%hi(D_...)` / `lw
  $v0,%lo(D_...)($v0)`.
- **Pseudo-instructions:** `li`, `la`, `move`, `b` expand to real instructions
  (`move rd,rs` → `addu rd,rs,$0`). splat disassembles to canonical form, so you
  see `ori $v0,$0,1` / `addu $v0,$0,$0` where a modern disassembler would print
  `li`/`move`.

---

## See also

- `PSX_REFERENCE.md` §2 - MIPS I ISA & instruction encoding in the decomp context.
- `docs/MATCHING_TECHNIQUES.md` §8 - how GCC 2.6.x emits these instructions byte-exactly.
- psx-spx CPU Specifications and the Nocash GTE overview (links in the Sources
  table) for authoritative encoding and cycle-accurate behavior.
