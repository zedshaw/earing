#ifndef struct_h
#define struct_h

typedef struct StructAlign {
    int is_packed;
    int is_two;
    int is_four;
    int is_eight;
    int is_largest;
    int size;
    int extent;
} StructAlign;

StructAlign StructAlign_create(void);
int StructAlign_indeterminate(StructAlign sa);
int StructAlign_multiple_cases(StructAlign sa);

#define StructAlign_is_packed(A) ((A).is_packed)
#define StructAlign_is_largest(A) ((A).is_largest)
#define StructAlign_is_two(A) ((A).is_two)
#define StructAlign_is_four(A) ((A).is_four)
#define StructAlign_is_eight(A) ((A).is_eight)

#endif
