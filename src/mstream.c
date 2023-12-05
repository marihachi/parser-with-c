#include <stdlib.h>
#include "mstream.h"
#include "util.h"

mstream_t *new_mstream() {
  mstream_t *ptr;
  ptr = malloc(sizeof(mstream_t));

  if (ptr == NULL) PANIC("FAIL: malloc in new_scanner()\n");

  // ptr->buf = buf;

  return ptr;
}
