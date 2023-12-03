#ifndef _UTIL_H
#define _UTIL_H

#include <stdio.h>

#define PANIC(message) do{printf(message);exit(EXIT_FAILURE);}while(0)

void mem_dump(void *address);

#endif
