#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

p_s_vector vector_alloc(size_t n){
  p_s_vector vectP = (p_s_vector)malloc(sizeof(s_vector));
  vectP->length = n;
  vectP->array = (double*)malloc(sizeof(double) * n);
  for(size_t i = 0 ; i < n ; i++){
    vectP->array[i] = 0;
  }
  return vectP;
}

void vector_free(p_s_vector p_vector){
  free(p_vector->array);
  p_vector->array = NULL;
  free(p_vector);
  p_vector = NULL;
}


void vector_set(p_s_vector p_vector, size_t i, double v){
  if(i < p_vector->length) p_vector->array[0] = v;
}

void vector_insert(p_s_vector p_vector, size_t i, double v){
  p_vector->length++;
  p_vector->array = realloc(p_vector->array, sizeof(s_vector) * p_vector->length);
  for(size_t j = p_vector->length - 1; j > i ; j--){
    p_vector->array[j] = p_vector->array[j-1];
  }
  p_vector->array[i] = v;
}

void vector_erase(p_s_vector p_vector, size_t i){
  p_vector->length--;
  for(size_t j = i ; j < p_vector->length ; j++){
    p_vector->array[j] = p_vector->array[j+1];
  }
}


// for debugging & testing
void vector_print(p_s_vector p_vector){
  for(size_t i = 0; i<p_vector->length ; i++){
    char comma = ',';
    char first_bracket = ' ';
    if(i==0){first_bracket = '{';}
    if(i == p_vector->length - 1) comma = '\0';
    printf("%c%.2lf%c",first_bracket, p_vector->array[i], comma);
  }
  printf("}\n");
}
