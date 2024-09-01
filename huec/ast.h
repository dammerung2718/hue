#ifndef HUE_AST_H
#define HUE_AST_H

#include "val.h"

/* abstract syntax tree */
struct hueAst {
    enum {
        HUE_PRINT,

        HUE_BINOP,
        HUE_LITERAL,
    } tag;

    union {
        const struct hueAst *const print;   /* HUE_PRINT */
        const struct hueVal *const literal; /* HUE_LITERAL */

        /* HUE_BINOP */
        const struct {
            const enum hueBinop op;
            const struct hueAst *const lhs;
            const struct hueAst *const rhs;
        } binop;
    };
};

/* constructors */
const struct hueAst *const hueAstPrint(const struct hueAst *const expr);
const struct hueAst *const hueAstBinop(const enum hueBinop op, const struct hueAst *const lhs, const struct hueAst *const rhs);
const struct hueAst *const hueAstLiteral(const struct hueVal *const val);

/* methods */
bool hueCmpAst(const struct hueAst *const lhs, const struct hueAst *const rhs);

#endif
