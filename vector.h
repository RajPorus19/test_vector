#include <stdlib.h>
#ifndef __VECTOR_H__
#define __VECTOR_H__
typedef struct struct_vector {
	size_t length;
	double* array;
} s_vector;
typedef s_vector* p_s_vector;
p_s_vector vector_alloc(size_t n);
// TODO correct free
void vector_free(p_s_vector p_vector);
void vector_set(p_s_vector p_vector, size_t i, double v);
void vector_insert(p_s_vector p_vector, size_t i, double v);
void vector_erase(p_s_vector p_vector, size_t i);
void vector_push_back(p_s_vector p_vector, double v);
void vector_pop_back(p_s_vector p_vector);
void vector_clear(p_s_vector p_vector);
int vector_empty(p_s_vector p_vector);
size_t vector_size(p_s_vector p_vector);
// for debugging & testing
void vector_print(p_s_vector p_vector);
#endif // __VECTOR_H__
