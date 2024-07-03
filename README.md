# sane_std

This is a personal standard library maintained as needed for other projects. The hope is that by using this library, my experience in writing C will get more enjoyable and generally easier.

WARNING! This will not be regularly maintained and will not necessarily contain well-thought-out functionality.

## Usage

All files in `sane_std` are STB-style. If you wish to include only the function declarations (not the definitions) and types, just include the header itself. For example:
```
#include "sane_std/string.h"
```

If you want to include the function defintions as well, specify the relevant `SANE_STD_*_IMPLEMENTATION` macro before including, where `*` is the captialized name of the header file. For example:
```
#define SANE_STD_STRINGS_IMPLEMENTATION
#include "sane_std/string.h"
```
