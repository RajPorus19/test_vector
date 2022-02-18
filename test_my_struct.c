#include "my_struct.h"

int test_my_struct_alloc();
/*
int test_my_struct_default_init(p_s_my_struct p_vector);
int test_my_struct_randoms_init(p_s_my_struct p_vector);
int test_my_struct_reset_to_default(p_s_my_struct p_vector);
int test_my_struct_copy(p_s_my_struct p_dest, p_s_my_struct p_src);
int test_my_struct_cmp(p_s_my_struct p_vector_a, p_s_my_struct p_vector_b);
int test_my_struct_print(p_s_my_struct p_vector);
*/

int main(void)
{
    int errors = 0;

    errors += test_my_struct_alloc();

    return 0;
}

int test_my_struct_alloc()
{
    p_s_my_struct my_struct = my_struct_alloc();
    my_struct_randoms_init(my_struct);
    my_struct_print(my_struct);
    my_struct_free(my_struct);
    return 0;
}
