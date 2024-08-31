#include "ast.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct hueAst *hueAstPrint(const struct hueAst *const expr)
{
    assert(expr != NULL);

    struct hueAst *const ast = malloc(sizeof(struct hueAst));
    assert(ast != NULL);

    ast->tag = HUE_PRINT;
    ast->print = expr;

    return ast;
}

struct hueAst *hueAstString(const char *const str)
{
    assert(str != NULL);

    struct hueAst *const ast = malloc(sizeof(struct hueAst));
    assert(ast != NULL);

    ast->tag = HUE_STRING;
    ast->string = str;

    return ast;
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

        case HUE_STRING:
            return strcmp(lhs->string, rhs->string) == 0;
    }
}
