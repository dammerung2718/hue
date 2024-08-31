#ifndef HUE_IO_H
#define HUE_IO_H

/* reads a utf8 file at `path`
 * returns null if file is not found or cannot be read */
char *hueReadFile(const char *const path);

#endif
