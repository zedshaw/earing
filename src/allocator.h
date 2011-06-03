#ifndef allocator_h
#define allocator_h

#include "token.h"
#include "module.h"

Token *Allocator_expression(Module *state, Token *tk);
void *Allocator_malloc(int size);
void *Allocator_realloc(void *mem, int new_size);
void Allocator_free(void *mem);
void Allocator_collect();

#endif
