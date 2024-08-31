#include "eval.h"

#include <assert.h>
#include <stddef.h>

const struct hueVal *const hueEval(const struct hueAst *const ast)
{
    assert(ast != NULL);

    switch (ast->tag) {
        case HUE_PRINT: {
            const struct hueVal *const expr = hueEval(ast->print);
            hueFmtVal(expr);
            return NULL;
        }

        case HUE_STRING:
            return hueValString(ast->string);
    }
}
