#include "util.h"

void mem_dump(void *address) {
  if (address == NULL) {
    printf("NULL ptr\n");
    return;
  }
  char *ptr = address;
  for (int y = 0; y < 4; y++) {
    printf("0x%016LX ", (unsigned long)(ptr + (y * 16)));
    for (int x = 0; x < 16; x++) {
      printf(" %02X", (unsigned char)(*(ptr + (y * 16 + x))));
    }
    printf("\n");
  }
}
