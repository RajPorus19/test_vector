#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

int main(void){
	p_s_vector vect = vector_alloc(3);
	vector_print(vect);
	vector_set(vect,1,10);
	vector_print(vect);
	vector_insert(vect,0,19);
	vector_print(vect);
	return 0;
};
