#include "val.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const struct hueVal *const hueValNumber(const double num)
{
    const struct hueVal *const ptr = malloc(sizeof(struct hueVal));
    assert(ptr != NULL);

    const struct hueVal val = {
        .tag = HUE_VAL_NUMBER,
        .number = num,
    };
    memcpy((void*)ptr, &val, sizeof(struct hueVal));

    return ptr;
}

const struct hueVal *const hueValString(const char *const str)
{
    const struct hueVal *const ptr = malloc(sizeof(struct hueVal));
    assert(ptr != NULL);

    const struct hueVal val = {
        .tag = HUE_VAL_STRING,
        .string = str,
    };
    memcpy((void*)ptr, &val, sizeof(struct hueVal));

    return ptr;
}

const struct hueVal *const hueValBinop(const enum hueBinop op, const struct hueVal *const lhs, const struct hueVal *const rhs)
{
    assert(lhs != NULL);
    assert(rhs != NULL);
    assert(lhs->tag == rhs->tag);

    const struct hueVal *const ptr = malloc(sizeof(struct hueVal));
    assert(ptr != NULL);

    switch (op) {
        case HUE_BINOP_ADD:
            return hueValNumber(lhs->number + rhs->number);
    }
}

void hueFmtVal(const struct hueVal *const val)
{
    assert(val != NULL);

    switch (val->tag) {
        case HUE_VAL_STRING:
            printf("%s", val->string);
            break;

        case HUE_VAL_NUMBER:
            printf("%f", val->number);
            break;
    }
}

bool hueCmpVal(const struct hueVal *const lhs, const struct hueVal *const rhs)
{
    assert(lhs != NULL);
    assert(rhs != NULL);

    if (lhs->tag != rhs->tag) {
        return false;
    }

    switch (lhs->tag) {
        case HUE_VAL_NUMBER:
            return lhs->number == rhs->number;
        case HUE_VAL_STRING:
            return strcmp(lhs->string, rhs->string) == 0;
    }
}
