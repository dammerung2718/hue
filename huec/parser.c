#include "parser.h"

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/* parsing state */
struct state {
    const bool succeeded;
    const char *const input;
    const struct hueAst *const expr;
};

static struct state begin(const char *const input)
{
    return (struct state){
        .succeeded = true,
        .input = input,
    };
}

static struct state skip(const char *const input)
{
    return (struct state){
        .succeeded = false,
        .input = input,
    };
}

static struct state ok(const char *const input, const struct hueAst *const expr)
{
    return (struct state){
        .succeeded = true,
        .input = input,
        .expr = expr,
    };
}

/* parsers */
static struct state skipWhitespace(const struct state state)
{
    const char *input = state.input;
    while (*input != '\0' && isspace(*input)) {
        input++;
    }
    return ok(input, NULL);
}

static struct state tag(
    const struct state state,
    const char *const tag
)
{
    assert(tag != NULL);

    const struct state next = skipWhitespace(state);
    if (strncmp(next.input, tag, strlen(tag)) != 0) {
        return skip(next.input);
    }

    return ok(next.input + strlen(tag), NULL);
}

static struct state string(const struct state state)
{
    const struct state next = skipWhitespace(state);

    if (*next.input != '"') {
        return skip(next.input);
    }

    const char *input = next.input + 1;
    while (*input != '\0' && *input != '"') {
        input++;
    }
    assert(*input == '"');
    input++;

    const int size = input - next.input - 2;
    const char *const buffer = malloc(size + 1);
    assert(buffer != NULL);
    strncpy((char*)buffer, next.input + 1, size);

    return ok(input, hueAstString(buffer));
}

static struct state print(const struct state state)
{
    const struct state printKeyword = tag(state, "print");
    if (!printKeyword.succeeded) {
        return skip(state.input);
    }

    const struct state expr = string(printKeyword);
    if (!expr.succeeded) {
        return skip(state.input);
    }

    return ok(expr.input, hueAstPrint(expr.expr));
}

const struct hueAst *const hueParse(const char *const str)
{
    const struct state ast = print(begin(str));
    assert(ast.succeeded);

    const struct state trailing = skipWhitespace(ast);
    assert(strlen(trailing.input) == 0);

    return ast.expr;
}
