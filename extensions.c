#include <string.h>
#include <assert.h>
#include "extensions.h"

// get_extension(filename) returns the address of the last occurence of charater '.'
// requires: filename not be NULL
// time: O(n), where n is the length of filename
const char *get_extension(const char *filename) {
        assert(filename);

        const char *tmp = filename;
        while (*filename != '\0') {
                if (*filename == '.') {
                        tmp = filename;
                }
                filename++;
        }
        if (*tmp != '.') return NULL;
        return tmp;
}
