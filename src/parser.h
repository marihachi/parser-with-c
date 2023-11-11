#ifndef _PARSER_H
#define _PARSER_H

#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "scanner.h"

node_t *parse(char *input, int input_length);

#endif
