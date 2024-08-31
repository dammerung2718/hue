#include "huec/lib.h"

#include <assert.h>
#include <stdio.h>

int main() {
    /* create file */
    FILE *const fp = fopen("test-file", "w");
    assert(fp != NULL);
    fprintf(fp, "Hello, world!\n");
    fclose(fp);

    /* read file */
    const char * const file = hueReadFile("test-file");
    assert(file != NULL);

    /* try read non-exist file */
    const char * const nonExist = hueReadFile("non-exist");
    assert(nonExist == NULL);
}
