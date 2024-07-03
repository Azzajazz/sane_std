#ifndef _SANE_STD_ALLOCATOR_H
#define _SANE_STD_ALLOCATOR_H 

#include <stddef.h>

typedef struct {
    void* (*allocate)(size_t);
    void  (*free)(void*);
} Allocator;

Allocator make_standard_allocator(void);



#ifdef SANE_STD_ALLOCATOR_IMPLEMENTATION

#include <stdlib.h>

Allocator make_standard_allocator() {
    return (Allocator){malloc, free};
}

#endif // SANE_STD_ALLOCATOR_IMPLEMENTATION 



#endif // _SANE_STD_ALLOCATOR_H
