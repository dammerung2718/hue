#ifndef HUE_AST_H
#define HUE_AST_H

#include <stdbool.h>

/* abstract syntax tree */
struct hueAst {
    enum {
        HUE_PRINT,
        HUE_STRING,
    } tag;

    const struct hueAst *print; /* HUE_PRINT */
    const char *string;         /* HUE_STRING */
};

/* constructors */
struct hueAst *hueAstPrint(const struct hueAst *const expr);
struct hueAst *hueAstString(const char *const str);

/* methods */
bool hueCmpAst(const struct hueAst *const lhs, const struct hueAst *const rhs);

#endif
