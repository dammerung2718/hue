#include "huec/lib.h"

#include <stddef.h>
#include <assert.h>

int main()
{
    const struct hueAst *const ast = hueParse("print \"Hello, world!\"");
    assert(ast != NULL);
    assert(hueCmpAst(
        ast,
        hueAstPrint(hueAstString("Hello, world!"))
    ));
}
