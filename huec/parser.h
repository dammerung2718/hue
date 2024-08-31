#ifndef HUE_PARSER_H
#define HUE_PARSER_H

#include "ast.h"

/* parses an ascii string into an abstract syntax tree */
const struct hueAst *const hueParse(const char *const str);

#endif
