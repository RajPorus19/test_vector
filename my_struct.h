#include <stddef.h>
#include <stdio.h>

#ifndef __MY_STRUCT_H__
#define __MY_STRUCT_H__

typedef struct struct_my_struct
{
    unsigned char *text;
    double number;
} s_my_struct;

typedef s_my_struct *p_s_my_struct;

p_s_my_struct my_struct_alloc();
void my_struct_free(p_s_my_struct p_vector);
void my_struct_default_init(p_s_my_struct p_vector);
void my_struct_randoms_init(p_s_my_struct p_vector);
void my_struct_reset_to_default(p_s_my_struct p_vector);
void my_struct_copy(p_s_my_struct p_dest, p_s_my_struct p_src);
int my_struct_cmp(p_s_my_struct p_vector_a, p_s_my_struct p_vector_b);
void my_struct_print(p_s_my_struct p_vector);

#endif