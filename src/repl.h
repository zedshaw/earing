#ifndef repl_h
#define repl_h

typedef char **(*complete_function)(const char *string, int start, int end);

void repl_init(complete_function func);
char *repl_prompt();

#endif
