#ifndef array_h
#define array_h

#include <stdlib.h>

typedef struct array_t {
    size_t size;
    size_t end;
    
    void *data[];
} array_t;

array_t *array_create();
void *array_pop(array_t *ary);
size_t array_add(array_t *ary, void *el);
array_t *array_extend(array_t *ary, size_t by);
array_t *array_clamp(array_t *ary);

#define array_length(A) ((A)->end)
#define array_max(A) ((A)->size)
#define array_isfull(A) ((A)->end == (A)->size)
#define array_isempty(A) ((A)->end == 0)
#define array_at(A,I) ((A)->data[(I)])
#define array_push(A, I) array_add((A), (I))
#define array_last(A) array_at((A), (A)->end-1)
#define array_set(A,I,V) array_at(A,I) = (V)
#define array_of(T, A, I) ((T *)array_at(A, I))

#endif
