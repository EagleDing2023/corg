#ifndef EXTENSIONS_H
#define EXTENSIONS_H

// get_extension(filename) returns a pointer to the last '.' in filename,
// or NULL if no '.' exists.
// requires: filename is not NULL
const char *get_extension(const char *filename);

#endif
