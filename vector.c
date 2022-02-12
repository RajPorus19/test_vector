#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

p_s_vector vector_alloc(size_t n)
{
  p_s_vector vector = malloc(sizeof(s_vector));

  if (vector == NULL)
    return vector;

  vector->length = n;
#if V2
  vector->capacity = n > 16 ? n + 8 - (n % 16) : 16;
  vector->array = malloc(sizeof(double) * vector->capacity);
#else
  vector->array = malloc(sizeof(double) * vector->length);
#endif

  for (size_t i = 0; i < n; i++)
  {
    vector->array[i] = 0.0;
  }

  if (vector->array == NULL)
  {
    free(vector);
    vector = NULL;
  }

  return vector;
}

void vector_realloc(p_s_vector p_vector, size_t n)
{

#if V2
  if (p_vector->length >= p_vector->capacity)
  {
    p_vector->capacity *= 2;
    n = sizeof(double) * p_vector->capacity;
    p_vector->array = realloc(p_vector->array, n);
    // printf("realloc\n");
  }
  else if (p_vector->length <= p_vector->capacity / 4)
  {
    p_vector->capacity /= 2;
    n = sizeof(double) * p_vector->capacity;
    p_vector->array = realloc(p_vector->array, n);
    // printf("realloc\n");
  }
#else
  p_vector->array = realloc(p_vector->array, sizeof(double) * n);
  // printf("realloc\n");
#endif
}

void vector_free(p_s_vector p_vector)
{
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
    printf("%lf, ", p_vector->array[i]);
  printf("%lf]\n", p_vector->array[p_vector->length - 1]);
  printf("length : %ld\n", p_vector->length);
#if V2
  printf("capacity : %ld\n", p_vector->capacity);
#endif
}

void vector_set(p_s_vector p_vector, size_t i, double v)
{
  if (p_vector->length < i)
    return;

  p_vector->array[i] = v;
}

void vector_insert(p_s_vector p_vector, size_t i, double v)
{
  if (p_vector->length < i)
    return;

  p_vector->length++;
  vector_realloc(p_vector, sizeof(double) * p_vector->length);
  for (size_t j = p_vector->length - 1; j > i; j--)
  {
    p_vector->array[j] = p_vector->array[j - 1];
  }
  p_vector->array[i] = v;
}

void vector_erase(p_s_vector p_vector, size_t i)
{
  if (p_vector->length < i)
    return;

  p_vector->length--;
  for (size_t j = i; j < p_vector->length; j++)
  {
    p_vector->array[j] = p_vector->array[j + 1];
  }
  vector_realloc(p_vector, sizeof(double) * p_vector->length);
}

void vector_push_back(p_s_vector p_vector, double v)
{
  p_vector->length++;
  p_vector->array = (double *)realloc(p_vector->array, sizeof(s_vector) * p_vector->length);
  p_vector->array[p_vector->length - 1] = v;
}

void vector_pop_back(p_s_vector p_vector)
{
  vector_erase(p_vector, p_vector->length - 1);
}

void vector_clear(p_s_vector p_vector)
{
  p_vector->length = 0;
  vector_realloc(p_vector, sizeof(double) * p_vector->length);
}

int vector_empty(p_s_vector p_vector)
{
  return p_vector->length == 0 ? 0 : 1;
}

size_t vector_size(p_s_vector p_vector)
{
  return p_vector->length;
}