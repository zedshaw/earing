#include "hash.h"
#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <cut/2.6/cut.h>
#include <stdlib.h>
#include <string.h>

typedef char input_t[256];

static int tokenize(char *string, ...)
{
    char **tokptr; 
    va_list arglist;
    int tokcount = 0;

    va_start(arglist, string);
    tokptr = va_arg(arglist, char **);
    while (tokptr) {
        while (*string && isspace((unsigned char) *string))
            string++;
        if (!*string)
            break;
        *tokptr = string;
        while (*string && !isspace((unsigned char) *string))
            string++;
        tokptr = va_arg(arglist, char **);
        tokcount++;
        if (!*string)
            break;
        *string++ = 0;
    }
    va_end(arglist);

    return tokcount;
}

static char *dupstring(char *str)
{
    int sz = strlen(str) + 1;
    char *new = malloc(sz);
    if (new)
        memcpy(new, str, sz);
    return new;
}

static hnode_t *new_node(void *c)
{
    static hnode_t few[5];
    static int count;

    if (count < 5)
        return few + count++;

    return NULL;
}

static void del_node(hnode_t *n, void *c)
{
}

void __CUT__hash_big_test(void)
{
    input_t in;
    hash_t *h = hash_create(HASHCOUNT_T_MAX, 0, 0);
    hnode_t *hn;
    hscan_t hs;
    char *tok1, *tok2, *val;
    const char *key;
    int prompt = 0;

    fclose(stdin);
    stdin = fopen("tests/test_data.txt", "r");
    ASSERT(stdin != NULL, "Couldn't open hash test data: tests/test_data.txt.");
    ASSERT(h != NULL, "hash_create failed");

    for (;;) {
        if (prompt)
            putchar('>');
        fflush(stdout);

        if (!fgets(in, sizeof(input_t), stdin))
            break;

        switch(in[0]) {
            case 'b':
                printf("%d\n", hash_val_t_bit);
                break;
            case 'a':
                if (tokenize(in+1, &tok1, &tok2, (char **) 0) != 2) {
                    puts("what?");
                    break;
                }
                key = dupstring(tok1);
                val = dupstring(tok2);

                ASSERT(key && val, "out of memory");
                ASSERT(hash_alloc_insert(h, key, val), "hash_alloc_insert failed");
                break;
            case 'd':
                if (tokenize(in+1, &tok1, (char **) 0) != 1) {
                    puts("what?");
                    break;
                }
                hn = hash_lookup(h, tok1);
                ASSERT(hn != NULL, "hash_lookup failed");

                val = hnode_get(hn);
                key = hnode_getkey(hn);
                hash_scan_delfree(h, hn);
                free((void *) key);
                free(val);
                break;
            case 'l':
                if (tokenize(in+1, &tok1, (char **) 0) != 1) {
                    puts("what?");
                    break;
                }
                hn = hash_lookup(h, tok1);
                ASSERT(hn != NULL, "hash_lookup failed");
                val = hnode_get(hn);
                puts(val);
                break;
            case 'n':
                printf("%lu\n", (unsigned long) hash_size(h));
                break;
            case 'c':
                printf("%lu\n", (unsigned long) hash_count(h));
                break;
            case 't':
                hash_scan_begin(&hs, h);
                while ((hn = hash_scan_next(&hs)))
                    printf("%s\t%s\n", (char*) hnode_getkey(hn),
                            (char*) hnode_get(hn));
                break;
            case 'q':
                exit(0);
                break;
            case '\0':
                break;
            case 'p':
                prompt = 1;
                break;
            case 's':
                hash_set_allocator(h, new_node, del_node, NULL);
                break;
            default:
                putchar('?');
                putchar('\n');
                break;
        }
    }
}

