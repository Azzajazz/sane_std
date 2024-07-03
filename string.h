#ifndef _SANE_STD_STRING_H
#define _SANE_STD_STRING_H

#ifdef SANE_STD_STRING_IMPLEMENTATION
#define SANE_STD_ALLOCATOR_IMPLEMENTATION
#endif
#include "sane_std/allocator.h"

#include <stdlib.h> // This has to be up here for wchar_t

typedef struct {
    int length;
    char* data;
} String;

String as_string(char*);

String from_wstr(wchar_t* wstr, Allocator allocator);


#ifdef SANE_STD_STRING_IMPLEMENTATION

// @TODO: Remove these includes?
#include <strings.h>


String as_string(char* cstr) {
    return (String){
        .length = strlen(cstr),
        .data = cstr,
    };
}

String from_wstr(wchar_t* wstr, Allocator allocator) {
    size_t mbs_length = 2 * (wcslen(wstr) + 1);
    char* data = allocator.allocate(mbs_length);
    size_t length = wcstombs(data, wstr, mbs_length);
    return (String){length, data};
}

#endif // SANE_STD_STRING_IMPLEMENTATION



#endif // _SANE_STD_STRING_H
