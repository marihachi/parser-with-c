#ifndef _UTIL_H
#define _UTIL_H

#define THROW(message) do{printf(message);exit(EXIT_FAILURE);}while(0)

void mem_dump(void *address);

#endif
