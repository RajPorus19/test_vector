#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void test_vector_alloc(int *counter, p_s_vector vect);
void test_insert_vector(int *counter, p_s_vector vect);
void test_vector_erase(int *counter, p_s_vector vect);
void test_vector_set(int *counter, p_s_vector vect);
void test_vector_push_back(int *counter, p_s_vector vect);
void test_vector_pop_back(int *counter, p_s_vector vect);
void test_vector_clear(int *counter, p_s_vector vect);
void test_vector_empty(int *counter, p_s_vector vect);
void test_vector_size(int *counter, p_s_vector vect);
void test_vector_get(int *counter, p_s_vector vect);

int main(void)
{
	int counter = 0;
	// run tests
	p_s_vector vect = vector_alloc(3);
	test_vector_alloc(&counter, vect);
	test_insert_vector(&counter, vect);
	test_vector_erase(&counter, vect);
	test_vector_set(&counter, vect);
	test_vector_push_back(&counter, vect);
	test_vector_pop_back(&counter, vect);
	test_vector_clear(&counter, vect);
	test_vector_empty(&counter, vect);
	test_vector_size(&counter, vect);
	test_vector_get(&counter, vect);
	// print result
	if (counter == 0)
		printf("All tests have passed successfuly ! :) \n");
	else
		printf("%d tests have failed :(  \n", counter);
	vector_free(vect);
	return 0;
};

void test_vector_alloc(int *counter, p_s_vector vect)
{
	int valid = 1;
	// assert length is 3
	if (vect->length != 3)
		valid++;
#if V2
	if (vect->capacity != 16)
		valid++;
#endif

	// assert all the doubles are equal to zero
	for (size_t i = 0; i < vect->length; i++)
	{
		if (vect->array[i] != 0)
			valid++;
	}
	if (valid != 1)
	{
		printf("alloc_vector did not work as expected.\n");
		*counter += 1;
	}
}

void test_insert_vector(int *counter, p_s_vector vect)
{
	int valid = 1;
	vector_insert(vect, 1, 10);
	// assert length is 4
	if (vect->length != 4)
		valid++;
	// assert remaining doubles have been shifted
	for (size_t i = 2; i < vect->length; i++)
	{
		if (vect->array[i] != 0)
			valid++;
	}
	// assert first element and insertion
	if (vect->array[0] != 0)
		valid++;
	if (vect->array[1] != 10)
		valid++;
	if (valid != 1)
	{
		printf("insert_vector did not work as expected.\n");
		*counter += 1;
	}
}

void test_vector_erase(int *counter, p_s_vector vect)
{
	int valid = 1;
	vector_erase(vect, 1);
	// assert length is 3
	if (vect->length != 3)
		valid++;
	// assert it's all equal to 0 (reuse of first function)
	test_vector_alloc(counter, vect);
	if (valid != 1)
	{
		printf("vector_erase did not work as expected.\n");
		*counter += 1;
	}
}

void test_vector_set(int *counter, p_s_vector vect)
{
	int valid = 1;
	vector_set(vect, 0, 10);
	// assert length is still 3
	if (vect->length != 3)
		valid++;
	// assert first element has been changed
	if (vect->array[0] != 10)
		valid++;
	// assert the remaining items are the same
	for (size_t i = 1; i < vect->length; i++)
	{
		if (vect->array[i] != 0)
			valid++;
	}
	if (valid != 1)
	{
		printf("set_vector did not work as expected.\n");
		*counter += 1;
	}
}

void test_vector_push_back(int *counter, p_s_vector vect)
{
	int valid = 1;
	// assert length is still 3
	if (vect->length != 3)
		valid++;
	vector_push_back(vect, 100);
	// assert length is now 4
	if (vect->length != 4)
		valid++;
	vector_push_back(vect, 200);
	// assert length is now 5
	if (vect->length != 5)
		valid++;
	// assert unique items with index
	if (vect->array[0] != 10)
		valid++;
	if (vect->array[1] != 0)
		valid++;
	if (vect->array[2] != 0)
		valid++;
	if (vect->array[3] != 100)
		valid++;
	if (vect->array[4] != 200)
		valid++;
	if (valid != 1)
	{
		printf("vector_push_back did not work as expected.\n");
		*counter += 1;
	}
}

void test_vector_pop_back(int *counter, p_s_vector vect)
{
	int valid = 1;
	// assert length is still 5
	if (vect->length != 5)
		valid++;
	vector_pop_back(vect);
	// assert length is now 4
	if (vect->length != 4)
		valid++;
	// assert unique items with index
	if (vect->array[0] != 10)
		valid++;
	if (vect->array[1] != 0)
		valid++;
	if (vect->array[2] != 0)
		valid++;
	if (vect->array[3] != 100)
		valid++;
	if (valid != 1)
	{
		printf("vector_pop_back did not work as expected.\n");
		*counter += 1;
	}
}

void test_vector_clear(int *counter, p_s_vector vect)
{
	int valid = 1;
	// assert length is still 4
	if (vect->length != 4)
		valid++;
	vector_clear(vect);
	// assert length is now 0
	if (vect->length != 0)
		valid++;
	if (valid != 1)
	{
		printf("vector_clear did not work as expected.\n");
		*counter += 1;
	}
}

void test_vector_empty(int *counter, p_s_vector vect)
{
	int valid = 1;
	// assert length is still 0
	if (vect->length != 0)
		valid++;

	int check = vector_empty(vect);
	// assert clear's result
	if (check != 1)
		valid++;
	vector_push_back(vect, 19);
	check = vector_empty(vect);
	// assert clear's result
	if (check != 0)
		valid++;
	// check pushed value
	if (vect->array[0] != 19)
		valid++;
	if (valid != 1)
	{
		printf("vector_empty did not work as expected.\n");
		*counter += 1;
	}
}

void test_vector_size(int *counter, p_s_vector vect)
{
	int valid = 1;
	// assert length is still 0
	if (vect->length != 1)
		valid++;
	int check = vector_size(vect);
	// assert clear's result
	if (check != 1)
		valid++;
	if (valid != 1)
	{
		printf("vector_empty did not work as expected.\n");
		*counter += 1;
	}
}

void test_vector_get(int *counter, p_s_vector vect)
{
	double num = vector_get(vect, 0);
	if (num != 19)
	{
		*counter += 1;
		printf("vector_get did not work as expected.\n");
	}
}