#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include "directives.h"
#include "module.h"
#include "util.h"
#include "repl.h"
#include <string.h>
#include "dis.h"
#include <unistd.h>
#include "error.h"
#include <gc/gc.h>
#include <gc/cord.h>

Module *current_module = NULL;

void query_functions(Function *func, void *ignored)
{
    printf("%.*s: %zu bytes of code, %d params defined\n", 
            func->len, func->name, func->code_len, func->nparams);
}

void run_repl(Module *state, const char *in_file) {
    printf("EaRing.  Copyright 2008 Zed A. Shaw.\n");
    printf("Done compiling %s.  Enter ? to get the function list.\n", in_file);
    char *cmd = NULL;
    current_module = state;
    repl_init(NULL);

    while((cmd = repl_prompt())) {
        if(cmd[0] == '?') {
            tst_traverse(state->functions, (tst_traverse_cb)query_functions, NULL);
        } else {
            run_function(state, cmd);
        }
    }
}


int main(int argc, char *argv[])
{
    CORD input = NULL;
    const char *in_file_name = NULL;
    FILE *in_file = NULL;
    Module *state = NULL;
    int opt;
    int disassemble = 0;
    const char *func = "main";
    int interactive = 0;
    int listing = 0;

    while((opt = getopt(argc, argv, "lhdf:i")) != -1) {
        switch(opt) {
            case 'd': disassemble = 1; break;
            case 'f': func = optarg; break;
            case 'i': interactive = 1; break;
            case 'l': listing = 1; break;
            case 'h': /// fall through!
            default:
                die(NULL, "USAGE: earing [-d | -i] [-f function] <file.asm>\n");
                return 1;
        }
    }

    if(optind >= argc) {
        die(NULL, "You have to give a file.  Use -h to see the usage.");
        return 1;
    }

    GC_INIT();

    in_file_name = argv[optind];
    in_file = fopen(in_file_name, "r");

    if(!in_file) {
        die(NULL, "Failed to open the input file %s", in_file_name);
    }

    input = CORD_from_file(in_file);

    state = Module_create(in_file_name, 1024);
    Module_register_default_directives(state);

    if(!Module_compile(state, CORD_to_const_char_star(input), CORD_len(input))) {
        die(state, "Parsing failed with %d errors.\n", state->errors);
        return 1;
    } else {
        if(listing) {
            tst_traverse(state->functions, (tst_traverse_cb)query_functions, NULL);
        } else if(disassemble) {
            dis_functions(state);
        } else if(interactive) {
            // go into interactive mode with the repl
            run_repl(state, in_file_name);
        } else {
            // run the given function or the "main" default
            run_function(state, func);
        }
    }

    return 0;
}
