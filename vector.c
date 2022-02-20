#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

p_s_vector vector_alloc(size_t n, size_t size_of_data, t_data_default_init data_default_init, t_data_reset_to_init data_reset_to_init, t_data_cpy data_cpy, t_data_print data_print)
{
  p_s_vector p_vector = malloc(sizeof(s_vector));

  if (p_vector == NULL)
    return p_vector;

  p_vector->length = n;

  p_vector->size_of_data = size_of_data;
  p_vector->data_default_init = data_default_init;
  p_vector->data_reset_to_init = data_reset_to_init;
  p_vector->data_cpy = data_cpy;
  p_vector->data_print = data_print;

#if V2
  p_vector->capacity = n > 16 ? n + 8 - (n % 16) : 16;
  p_vector->array = malloc(p_vector->size_of_data * p_vector->capacity);
#else
  p_vector->array = malloc(p_vector->size_of_data * p_vector->length);
#endif

  for (size_t i = 0; i < n; i++)
  {
    p_vector->data_default_init(p_vector->array + i * p_vector->size_of_data);
  }

  if (p_vector->array == NULL)
  {
    free(p_vector);
    p_vector = NULL;
  }

  return p_vector;
}

void vector_realloc(p_s_vector p_vector, size_t n)
{
#if V2
  if (p_vector->length >= p_vector->capacity)
  {
    p_vector->capacity *= 2;
    n = p_vector->size_of_data * p_vector->capacity;
    p_vector->array = realloc(p_vector->array, n);
  }
  else if (p_vector->length <= p_vector->capacity / 4 && p_vector->capacity / 2 >= 16)
  {
    p_vector->capacity /= 2;
    n = p_vector->size_of_data * p_vector->capacity;
    p_vector->array = realloc(p_vector->array, n);
  }
#else
  p_vector->array = realloc(p_vector->array, n);
#endif
}

void vector_free(p_s_vector p_vector)
{
  for (size_t i = 0; i < p_vector->length; i++)
  {
    p_vector->data_reset_to_init(p_vector->array + i * p_vector->size_of_data);
  }
  free(p_vector->array);
  free(p_vector);
}

void vector_print(p_s_vector p_vector)
{
  printf("[");
  if (p_vector->length == 0)
  {
    printf("]\n");
    return;
  }
  for (size_t i = 0; i < p_vector->length - 1; i++)
    p_vector->data_print(p_vector->array + i * p_vector->size_of_data);
  p_vector->data_print(p_vector->array + (p_vector->length - 1) * p_vector->size_of_data);
  printf("]\n");
  printf("length : %ld\n", p_vector->length);
#if V2
  printf("capacity : %ld\n", p_vector->capacity);
#endif
}

void vector_set(p_s_vector p_vector, size_t i, void *v)
{
  if (p_vector->length < i)
    return;

  p_vector->data_cpy(v, p_vector->array + i * p_vector->size_of_data);
}

void vector_get(p_s_vector p_vector, size_t i, void *v)
{
  if (p_vector->length < i)
    return;

  p_vector->data_cpy(p_vector->array + i * p_vector->size_of_data, v);
}

void vector_insert(p_s_vector p_vector, size_t i, void *v)
{
  if (p_vector->length < i)
    return;

  p_vector->length++;
  vector_realloc(p_vector, p_vector->size_of_data * p_vector->length);
  for (size_t j = p_vector->length - 1; j > i; j--)
  {
    vector_set(p_vector, j, p_vector->array + (j - 1) * p_vector->size_of_data);
  }
  vector_set(p_vector, i, v);
}

void vector_erase(p_s_vector p_vector, size_t i)
{
  if (p_vector->length < i)
    return;

  p_vector->length--;
  for (size_t j = i; j < p_vector->length; j++)
  {
    vector_set(p_vector, j, p_vector->array + (j + 1) * p_vector->size_of_data);
  }
  vector_realloc(p_vector, p_vector->size_of_data * p_vector->length);
}

void vector_push_back(p_s_vector p_vector, void *v)
{
  p_vector->length++;
  vector_realloc(p_vector, p_vector->size_of_data * p_vector->length);
  vector_set(p_vector, p_vector->length - 1, v);
}

void vector_pop_back(p_s_vector p_vector)
{
  vector_erase(p_vector, p_vector->length - 1);
}

void vector_clear(p_s_vector p_vector)
{
  p_vector->length = 0;
  vector_realloc(p_vector, p_vector->size_of_data * p_vector->length);
}

int vector_empty(p_s_vector p_vector)
{
  return p_vector->length == 0 ? 1 : 0;
}

size_t vector_size(p_s_vector p_vector)
{
  return p_vector->length;
}