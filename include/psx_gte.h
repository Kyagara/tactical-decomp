/* PSX GTE (COP2) inline macros. Shapes from Sony's SDK headers
 * as vendored by the Silent Hill decomp (psyq/inline_c.h, psyq/gtemac.h,
 * inline_no_dmpsx.h); _b variants omit the two lead nops. */

#ifndef PSX_GTE_H
#define PSX_GTE_H

#if defined(__mips__)

#define gte_ldrgb(p) __asm__ volatile( \
    "lwc2 $6, 0(%0)" : : "r"(p))

#define gte_ldlvl(p) __asm__ volatile( \
    "lwc2 $9, 0(%0)\n\tlwc2 $10, 4(%0)\n\tlwc2 $11, 8(%0)" : : "r"(p))

#define gte_lddp(v) __asm__ volatile( \
    "mtc2 %0, $8" : : "r"(v))

/* Oracle order is SXY0, SXY2, SXY1 ($12, $14, $13). */
#define gte_ldsxy3(v0, v1, v2) __asm__ volatile(   \
    "mtc2 %0, $12\n\tmtc2 %2, $14\n\tmtc2 %1, $13" \
    : : "r"(v0), "r"(v1), "r"(v2))

#define gte_ldsz3(v0, v1, v2) __asm__ volatile(    \
    "mtc2 %0, $17\n\tmtc2 %1, $18\n\tmtc2 %2, $19" \
    : : "r"(v0), "r"(v1), "r"(v2))

#define gte_ldsz4(v0, v1, v2, v3) __asm__ volatile( \
    "mtc2 %0, $16\n\tmtc2 %1, $17\n\t"              \
    "mtc2 %2, $18\n\tmtc2 %3, $19"                  \
    : : "r"(v0), "r"(v1), "r"(v2), "r"(v3))

#define gte_ldlzc(v) __asm__ volatile( \
    "mtc2 %0, $30" : : "r"(v))

#define gte_strgb(p) __asm__ volatile( \
    "swc2 $22, 0(%0)" : : "r"(p) : "memory")

#define gte_ctc2(v, r) __asm__ volatile("ctc2 %0, $%1" : : "r"(v), "i"(r))
#define gte_mfc2(dst, r) __asm__ volatile("mfc2 %0, $%1" : "=r"(dst) : "i"(r))
#define gte_cfc2(dst, r) __asm__ volatile("cfc2 %0, $%1" : "=r"(dst) : "i"(r))

#define gte_nclip() __asm__ volatile("nop\n\tnop\n\t.word 0x4B400006")
#define gte_avsz3_b() __asm__ volatile(".word 0x4B58002D")
#define gte_avsz4_b() __asm__ volatile(".word 0x4B68002E")
#define gte_dpcl_b() __asm__ volatile(".word 0x4A680029")
#define gte_intpl_b() __asm__ volatile(".word 0x4A980011")

#else /* host build: GTE absent -- declaration-syntax check only */

#define gte_ldrgb(p) ((void) (p))
#define gte_ldlvl(p) ((void) (p))
#define gte_lddp(v) ((void) (v))
#define gte_ldsxy3(v0, v1, v2) \
    do {                       \
        (void) (v0);           \
        (void) (v1);           \
        (void) (v2);           \
    } while (0)
#define gte_ldsz3(v0, v1, v2) \
    do {                      \
        (void) (v0);          \
        (void) (v1);          \
        (void) (v2);          \
    } while (0)
#define gte_ldsz4(v0, v1, v2, v3) \
    do {                          \
        (void) (v0);              \
        (void) (v1);              \
        (void) (v2);              \
        (void) (v3);              \
    } while (0)
#define gte_ldlzc(v) ((void) (v))
#define gte_strgb(p) ((void) (p))
#define gte_ctc2(v, r) \
    do {               \
        (void) (v);    \
        (void) (r);    \
    } while (0)
#define gte_mfc2(dst, r) \
    do {                 \
        (void) (dst);    \
        (void) (r);      \
    } while (0)
#define gte_cfc2(dst, r) \
    do {                 \
        (void) (dst);    \
        (void) (r);      \
    } while (0)
#define gte_nclip() ((void) 0)
#define gte_avsz3_b() ((void) 0)
#define gte_avsz4_b() ((void) 0)
#define gte_dpcl_b() ((void) 0)
#define gte_intpl_b() ((void) 0)

#endif /* __mips__ */

#endif /* PSX_GTE_H */
