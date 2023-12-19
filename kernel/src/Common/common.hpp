#ifndef COMMON_INC_

#include <stdint.h>
#include <stddef.h>
#ifndef _LIMINE_H
#include <limine.h>
#endif



// GCC and Clang reserve the right to generate calls to the following
// 4 functions even if they are not directly called.
// Implement them as the C specification mandates.
// DO NOT remove or rename these functions, or stuff will eventually break!
// They CAN be moved to a different .c file.

void *memcpy(void *dest, const void *src, size_t n);

void *memset(void *s, int c, size_t n) ;

void *memmove(void *dest, const void *src, size_t n) ;
int memcmp(const void *s1, const void *s2, size_t n) ;

// Halt and catch fire function.
void hcf(void) ;
#define COMMON_INC_

// The following will be our kernel's entry point.
// If renaming _start() to something else, make sure to change the
// linker script accordingly.
#endif
