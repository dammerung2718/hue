#include "val.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

void hueFmtVal(const struct hueVal *const val)
{
    assert(val != NULL);

    switch (val->tag) {
        case HUE_VAL_STRING:
            printf("%s", val->string);
            break;
    }
}
