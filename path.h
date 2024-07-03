#ifndef _SANE_STD_PATH_H
#define _SANE_STD_PATH_H

#ifdef SANE_STD_PATH_IMPLEMENTATION
#define SANE_STD_STRING_IMPLEMENTATION
#endif
#include "sane_std/string.h"

/*
 * Returns the stem of a file path (everything after the last directory delimiter)
 *
 * @Note: This currently only supports Windows paths, where the file delimeter is \
 */
String path_stem(String file_path) {
    int stem_start = file_path.length - 1;

    // Skip trailing \ characters
    while (file_path.data[stem_start] == '\\') {
        stem_start--;
        if (stem_start < 0)
            return as_string("");
    }
    
    // Get the stem
    int stem_length = 0;
    while (file_path.data[stem_start] != '\\') {
        stem_start--;
        stem_length++;
    }

    return (String){
        .data = file_path.data + stem_start + 1,
        .length = stem_length,
    };
}

#ifdef SANE_STD_PATH_IMPLEMENTATION


#endif // SANE_STD_PATH_IMPLEMENTATION  

#endif // _SANE_STD_PATH_H
