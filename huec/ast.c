#include "ast.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

const struct hueAst *const hueAstPrint(const struct hueAst *const expr)
{
    assert(expr != NULL);

    const struct hueAst *const ptr = malloc(sizeof(struct hueAst));
    assert(ptr != NULL);

    const struct hueAst ast = {
        .tag = HUE_PRINT,
        .print = expr,
    };
    memcpy((void*)ptr, &ast, sizeof(struct hueAst));

    return ptr;
}

const struct hueAst *const hueAstBinop(const enum hueBinop op, const struct hueAst *const lhs, const struct hueAst *const rhs)
{
    assert(lhs != NULL);
    assert(rhs != NULL);

    const struct hueAst *const ptr = malloc(sizeof(struct hueAst));
    assert(ptr != NULL);

    const struct hueAst ast = {
        .tag = HUE_BINOP,
        .binop = { .op = op, .lhs = lhs, .rhs = rhs }
    };
    memcpy((void*)ptr, &ast, sizeof(struct hueAst));

    return ptr;
}

const struct hueAst *const hueAstLiteral(const struct hueVal *const val)
{
    assert(val != NULL);

    const struct hueAst *const ptr = malloc(sizeof(struct hueAst));
    assert(ptr != NULL);

    const struct hueAst ast = {
        .tag = HUE_LITERAL,
        .literal = val,
    };
    memcpy((void*)ptr, &ast, sizeof(struct hueAst));

    return ptr;
}

bool hueCmpAst(const struct hueAst *const lhs, const struct hueAst *const rhs)
{
    assert(lhs != NULL);
    assert(rhs != NULL);

    if (lhs->tag != rhs->tag) {
        return false;
    }

    switch (lhs->tag) {
        case HUE_PRINT:
            return hueCmpAst(lhs->print, rhs->print);

        case HUE_BINOP:
            if (lhs->binop.op != rhs->binop.op) {
                return false;
            }
            if (!hueCmpAst(lhs->binop.lhs, rhs->binop.lhs)) {
                return false;
            }
            if (!hueCmpAst(lhs->binop.rhs, rhs->binop.rhs)) {
                return false;
            }
            return true;

        case HUE_LITERAL:
            return hueCmpVal(lhs->literal, rhs->literal);
    }
}
