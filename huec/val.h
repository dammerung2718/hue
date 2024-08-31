#ifndef HUE_VAL_H
#define HUE_VAL_H

struct hueVal {
    const enum { HUE_VAL_STRING } tag;

    union {
        const char *string;
    };
};

/* constructors */
const struct hueVal *const hueValString(const char *const str);

/* methods */
void hueFmtVal(const struct hueVal *const val);

#endif
