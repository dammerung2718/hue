#include "huec/lib.h"

#include <assert.h>
#include <stddef.h>

int main()
{
    const struct hueAst *const ast = hueParse("1 + 2");
    assert(ast != NULL);
    assert(hueCmpAst(ast,
        hueAstBinop(
            HUE_BINOP_ADD,
            hueAstLiteral(hueValNumber(1)),
            hueAstLiteral(hueValNumber(2))
    )));
    assert(hueCmpVal(
        hueEval(ast),
        hueValNumber(3)
    ));
}
