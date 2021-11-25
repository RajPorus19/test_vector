#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void test_set_vector(int* counter);
void test_insert_vector(int* counter);

int main(void){
	int counter = 0;
	test_set_vector(&counter);
	test_insert_vector(&counter);
	if(counter==0) printf("All tests have passed successfuly ! :) \n");
	else printf("%d tests have failed :(  \n",counter);
	return 0;
};

void test_set_vector(int* counter){
	int valid = 1;
	p_s_vector vect = vector_alloc(3);
	for(size_t i = 0 ; i < vect->length ; i++){
		if(vect->array[i] != 0) valid++;
	}
	if(valid!=1) {
		printf("set_vector did not work as expected.\n");
		*counter += 1;
	}
	free(vect);
}


void test_insert_vector(int* counter){
	int valid = 1;
	p_s_vector vect = vector_alloc(3);
	vector_insert(vect, 1, 10);
	vector_print(vect);
	for(size_t i = 2 ; i < vect->length ; i++){
		if(vect->array[i] != 0) valid++;
	}
	if(vect->array[0] != 0) valid++;
	if(vect->array[1] != 10) valid++;
	if(valid!=1) {
		printf("set_vector did not work as expected.\n");
		*counter += 1;
	}
	free(vect);
}
