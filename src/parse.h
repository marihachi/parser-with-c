#ifndef _PARSE_H
#define _PARSE_H

#include "node.h"
#include "scan.h"

node_t *parse(char *input, int input_length);
node_t *parse_decls(scanner_t *s);
node_t *parse_decl(scanner_t *s);
node_t *parse_statement(scanner_t *s);
node_t *parse_expression(scanner_t *s);

#endif
