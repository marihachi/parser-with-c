#ifndef _PARSE_H
#define _PARSE_H

#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "scan.h"

node_t *parse(char *input, int input_length);

#endif
