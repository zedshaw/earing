#include <stdio.h>
#include "repl.h"
#include <string.h>
#include <stdlib.h>
#include <gc/gc.h>

void repl_init(complete_function func)
{
    // does nothing until I can figure out how to portably use readline
}

char *repl_prompt()
{
    char *line = GC_MALLOC(1024 * sizeof(char));

    printf(">>> ");

    char *result = fgets(line, 1023, stdin);
     
    if(result) {
        result[strlen(result)-1] = '\0';
    }

    return result;
}
