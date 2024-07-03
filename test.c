#define SANE_STD_PATH_IMPLEMENTATION
#include "sane_std/path.h"
#define SANE_STD_STRING_IMPLEMENTATION
#include "sane_std/string.h"
#define SANE_STD_ALLOCATOR_IMPLEMENTATION
#include "sane_std/allocator.h"

#include <stdio.h>

int main() {
    wchar_t* wpath = L"path\\to\\something.c\\\\\\";
    String path = from_wstr(wpath, make_standard_allocator());
    String stem = path_stem(path);
    printf("%.*s\n", stem.length, stem.data);
    return 0;
}
