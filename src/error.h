#ifndef error_h
#define error_h

#include "module.h"

void error(Module *state, const char *format, ...);
void die(Module *state, const char *format, ...);

#endif
