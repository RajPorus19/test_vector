#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "random.h"
#include "vector.h"

void insert_erase_random(p_s_vector p_vector, size_t n)
{
    printf("Inserting and removing %ld values randomly\n", n);
    for (size_t i = 0; i < n; i++)
    {
        size_t position = random_size_t(0, p_vector->length - 1);
        double value = random_double(-10, 10);
        // printf("%ld : insert %f at position %ld\n", i, value, position);
        vector_insert(p_vector, position, value);
        // vector_print(p_vector);
    }
    for (size_t i = 0; i < n; i++)
    {
        size_t position = random_size_t(0, p_vector->length - 1);
        // printf("%ld : remove at position %ld\n", i, position);
        vector_erase(p_vector, position);
        // vector_print(p_vector);
    }
}

void insert_erase_head(p_s_vector p_vector, size_t n)
{
    printf("Inserting and removing %ld values in head of list\n", n);
    for (size_t i = 0; i < n; i++)
    {
        size_t position = 0;
        double value = random_double(-10, 10);
        printf("%ld :  array[%ld] = %f\n", i, position, value);
        vector_insert(p_vector, position, value);
        vector_print(p_vector);
        vector_erase(p_vector, position);
        vector_print(p_vector);
    }
}

void insert_erase_tail(p_s_vector p_vector, size_t n)
{
    printf("Inserting and removing %ld values in tail of list\n", n);
    for (size_t i = 0; i < n; i++)
    {
        size_t position = p_vector->length - 1;
        double value = random_double(-10, 10);
        printf("%ld :  array[%ld] = %f\n", i, position, value);
        vector_push_back(p_vector, value);
        vector_print(p_vector);
        vector_pop_back(p_vector);
        vector_print(p_vector);
    }
}

void read_write_random(p_s_vector p_vector, size_t n)
{
    printf("Read and write %ld values randomly\n", n);
    for (size_t i = 0; i < n; i++)
    {
        size_t position = random_size_t(0, p_vector->length - 1);
        double value = random_double(-10, 10);
        printf("%ld :  array[%ld] = %f\n", i, position, value);
        vector_set(p_vector, position, value);
        vector_print(p_vector);
    }
}

void read_write_sequential(p_s_vector p_vector, size_t n)
{
    printf("Read and write %ld times all values of array\n", n);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t pos = 0; pos < p_vector->length; pos++)
        {
            double value = random_double(-10, 10);
            printf("%ld :  array[%ld] = %f\n", i, pos, value);
            vector_set(p_vector, pos, value);
        }
        vector_print(p_vector);
    }
}

void bubble_sort(p_s_vector p_vector, size_t n)
{
    printf("Write all values of array and sort %ld times\n", n);
    for (size_t a = 0; a < n; a++)
    {
        read_write_sequential(p_vector, 1);

        double tmp = 0;
        for (size_t i = p_vector->length - 1; i > 0; i--)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (p_vector->array[j + 1] < p_vector->array[j])
                {
                    tmp = p_vector->array[j + 1];
                    p_vector->array[j + 1] = p_vector->array[j];
                    p_vector->array[j] = tmp;
                }
            }
        }
        vector_print(p_vector);
    }
}

int main(int argc, char *argv[])
{
    printf("BENCH VECTOR\n");

    char *test_name = "";
    size_t length;
    size_t n;

    if (argc < 4)
    {
        printf("array length\n");
        scanf("%ld", &length);
        printf("Tests number\n");
        scanf("%ld", &n);
        printf("Test name\n");
        scanf("%s", &test_name[0]);
    }
    else
    {
        length = atoi(argv[1]);
        n = atoi(argv[2]);
        test_name = argv[3];
    }

    printf("Test name : %s\n", test_name);
    printf("array length : %ld\n", length);
    printf("Tests number : %ld\n", n);

    p_s_vector vector = vector_alloc(length);

    if (strcmp(test_name, "insert_erase_random") == 0)
        insert_erase_random(vector, n);
    else if (strcmp(test_name, "insert_erase_head") == 0)
        insert_erase_head(vector, n);
    else if (strcmp(test_name, "insert_erase_tail") == 0)
        insert_erase_tail(vector, n);
    else if (strcmp(test_name, "read_write_random") == 0)
        read_write_random(vector, n);
    else if (strcmp(test_name, "read_write_sequential") == 0)
        read_write_sequential(vector, n);
    else if (strcmp(test_name, "bubble_sort") == 0)
        bubble_sort(vector, n);
    else
        printf("Write a valid test name\n");

    vector_free(vector);

    return 1;
}