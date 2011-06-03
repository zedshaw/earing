/*
 * This program attempts to determine struct layout rules for the compiler
 * in use.  It is only approximate, of course.  It looks for:
 *  packed (no gaps)
 *  aligned on 4 bytes
 *  aligned on 8 bytes
 *  aligned on sizeof(largest member)
 * Suggestions for further improvements are welcome; send to 
 *   mpi-bugs@mcs.anl.gov
 *
 * The IBM AIX compiler xlC will produce multiple packings.  Try
 *   xlC -qalign=twobyte structlayout.c
 *   xlC -qalign=packed structlayout.c
 *   xlC -qalign=power structlayout.c
 */
#include "struct.h"



StructAlign StructAlign_create(void) 
{
    StructAlign sa = {
        .is_packed  = 1,
        .is_two     = 1,
        .is_four    = 1,
        .is_eight   = 1,
        .is_largest = 1,
        .size = 0,
        .extent = 0
    };

    struct { char a; int b; } char_int;
    struct { char a; short b; } char_short;
    struct { char a; long b; } char_long;
    struct { char a; float b; } char_float;
    struct { char a; double b; } char_double;
    struct { char a; int b; char c; } char_int_char;
    struct { char a; short b; char c; } char_short_char;
    struct { char a; long double b; } char_long_double;

    sa.size = sizeof(char) + sizeof(int);
    sa.extent = sizeof(char_int);
    if (sa.size != sa.extent) sa.is_packed = 0;
    if ( (sa.extent % sizeof(int)) != 0) sa.is_largest = 0;
    if ( (sa.extent % 2) != 0) sa.is_two = 0;
    if ( (sa.extent % 4) != 0) sa.is_four = 0;
    if (sizeof(int) == 8 && (sa.extent % 8) != 0) sa.is_eight = 0;

    sa.size = sizeof(char) + sizeof(short);
    sa.extent = sizeof(char_short);
    if (sa.size != sa.extent) sa.is_packed = 0;
    if ( (sa.extent % sizeof(short)) != 0) sa.is_largest = 0;
    if ( (sa.extent % 2) != 0) sa.is_two = 0;
    if (sizeof(short) == 4 && (sa.extent % 4) != 0) sa.is_four = 0;
    if (sizeof(short) == 8 && (sa.extent % 8) != 0) sa.is_eight = 0;

    sa.size = sizeof(char) + sizeof(long);
    sa.extent = sizeof(char_long);
    if (sa.size != sa.extent) sa.is_packed = 0;
    if ( (sa.extent % sizeof(long)) != 0) sa.is_largest = 0;
    if ( (sa.extent % 2) != 0) sa.is_two = 0;
    if ( (sa.extent % 4) != 0) sa.is_four = 0;
    if (sizeof(long) == 8 && (sa.extent % 8) != 0) sa.is_eight = 0;

    sa.size = sizeof(char) + sizeof(float);
    sa.extent = sizeof(char_float);
    if (sa.size != sa.extent) sa.is_packed = 0;
    if ( (sa.extent % sizeof(float)) != 0) sa.is_largest = 0;
    if ( (sa.extent % 2) != 0) sa.is_two = 0;
    if ( (sa.extent % 4) != 0) sa.is_four = 0;
    if (sizeof(float) == 8 && (sa.extent % 8) != 0) sa.is_eight = 0;

    sa.size = sizeof(char) + sizeof(double);
    sa.extent = sizeof(char_double);
    if (sa.size != sa.extent) sa.is_packed = 0;
    if ( (sa.extent % sizeof(double)) != 0) sa.is_largest = 0;
    if ( (sa.extent % 2) != 0) sa.is_two = 0;
    if ( (sa.extent % 4) != 0) sa.is_four = 0;
    if (sizeof(double) == 8 && (sa.extent % 8) != 0) sa.is_eight = 0;

    sa.size = sizeof(char) + sizeof(long double);
    sa.extent = sizeof(char_long_double);
    if (sa.size != sa.extent) sa.is_packed = 0;
    if ( (sa.extent % sizeof(long double)) != 0) sa.is_largest = 0;
    if ( (sa.extent % 2) != 0) sa.is_two = 0;
    if ( (sa.extent % 4) != 0) sa.is_four = 0;
    if (sizeof(long double) >= 8 && (sa.extent % 8) != 0) sa.is_eight = 0;

    /* char int char helps separate largest from 4/8 aligned */
    sa.size = sizeof(char) + sizeof(int) + sizeof(char);
    sa.extent = sizeof(char_int_char);
    if (sa.size != sa.extent) sa.is_packed = 0;
    if ( (sa.extent % sizeof(int)) != 0) sa.is_largest = 0;
    if ( (sa.extent % 2) != 0) sa.is_two = 0;
    if ( (sa.extent % 4) != 0) sa.is_four = 0;
    if (sizeof(int) == 8 && (sa.extent % 8) != 0) sa.is_eight = 0;

    /* char short char helps separate largest from 4/8 aligned */
    sa.size = sizeof(char) + sizeof(short) + sizeof(char);
    sa.extent = sizeof(char_short_char);
    if (sa.size != sa.extent) sa.is_packed = 0;
    if ( (sa.extent % sizeof(short)) != 0) sa.is_largest = 0;
    if ( (sa.extent % 2) != 0) sa.is_two = 0;
    if (sizeof(short) == 4 && (sa.extent % 4) != 0) sa.is_four = 0;
    if (sizeof(short) == 8 && (sa.extent % 8) != 0) sa.is_eight = 0;

    /* If aligned mod 8, it will be aligned mod 4 */
    if (sa.is_eight) { sa.is_four = 0; sa.is_two = 0; }

    if (sa.is_four) sa.is_two = 0;

    /* largest superceeds eight */
    if (sa.is_largest) sa.is_eight = 0;

    return sa;
}


int StructAlign_indeterminate(StructAlign sa) {
    if (sa.is_packed + sa.is_largest + sa.is_two + sa.is_four + sa.is_eight == 0) {
        return 1;
    } else {
        return 0;
    }
}

int StructAlign_multiple_cases(StructAlign sa) {
	if (sa.is_packed + sa.is_largest + sa.is_two + sa.is_four + sa.is_eight != 1) {
        return 1;
	} else {
        return 0;
    }
}

