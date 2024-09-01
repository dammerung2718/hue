#ifndef HUE_VAL_H
#define HUE_VAL_H

#include "binop.h"

#include <stdbool.h>

struct hueVal {
    const enum {
        HUE_VAL_NUMBER,
        HUE_VAL_STRING
    } tag;

    union {
        const double number;
        const char *string;
    };
};

/* constructors */
const struct hueVal *const hueValNumber(const double num);
const struct hueVal *const hueValString(const char *const str);

/* methods */
const struct hueVal *const hueValBinop(const enum hueBinop op, const struct hueVal *const lhs, const struct hueVal *const rhs);
void hueFmtVal(const struct hueVal *const val);
bool hueCmpVal(const struct hueVal *const lhs, const struct hueVal *const rhs);

#endif
