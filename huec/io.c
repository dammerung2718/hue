#include "io.h"

#include <stdio.h>
#include <stdlib.h>

char *hueReadFile(const char *const path)
{
    FILE *const file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    const long size = ftell(file);
    rewind(file);

    char *const buffer = malloc(size + 1);
    if (buffer == NULL) {
        fclose(file);
        return NULL;
    }

    fread(buffer, size, 1, file);
    buffer[size] = '\0';
    fclose(file);

    /* TODO: check buffer has a valid utf8 bytes list */

    return buffer;
}
