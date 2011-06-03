#ifndef directives_h
#define directives_h

#include "module.h"

typedef struct Directive {
    int len;
    CORD name;
    Module_directive_cb call;
    Module_directive_cb destroy;
} Directive;

void Module_register_default_directives(Module *state);

void *Library_search(Module *state, Token *module, Token *name);

#endif
