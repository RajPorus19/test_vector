#include <stddef.h>

#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef void (*t_data_default_init)(void *p_data);
typedef void (*t_data_reset_to_init)(void *p_data);
typedef void (*t_data_cpy)(void *p_data_src, void *p_data_dst);
typedef void (*t_data_print)(void *p_data);

typedef struct struct_vector
{
    size_t length;
    void *array;
#if V2
    size_t capacity;
#endif

    t_data_default_init data_default_init;
    t_data_reset_to_init data_reset_to_init;
    t_data_cpy data_cpy;
    t_data_print data_print;
    size_t size_of_data;

} s_vector;

typedef s_vector *p_s_vector;

p_s_vector vector_alloc(size_t n, size_t size_of_data, t_data_default_init data_default_init, t_data_reset_to_init data_reset_to_init, t_data_cpy data_cpy, t_data_print data_print);
void vector_realloc(p_s_vector p_vector, size_t n);
void vector_free(p_s_vector p_vector);
void vector_print(p_s_vector p_vector);
void vector_set(p_s_vector p_vector, size_t i, void *v);
void vector_get(p_s_vector p_vector, size_t i, void *v);
void vector_insert(p_s_vector p_vector, size_t i, void *v);
void vector_erase(p_s_vector p_vector, size_t i);
void vector_push_back(p_s_vector p_vector, void *v);
void vector_pop_back(p_s_vector p_vector);
void vector_clear(p_s_vector p_vector);
int vector_empty(p_s_vector p_vector);
size_t vector_size(p_s_vector p_vector);

#endif