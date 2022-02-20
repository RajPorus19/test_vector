#include "my_struct.h"

int test_my_struct_alloc();
int test_my_struct_default_init(p_s_my_struct my_struct);
int test_my_struct_randoms_init(p_s_my_struct my_struct);
int test_my_struct_copy(p_s_my_struct p_src, p_s_my_struct p_dest);
/*
int test_my_struct_reset_to_default(p_s_my_struct my_struct);
int test_my_struct_cmp(p_s_my_struct my_struct_a, p_s_my_struct my_struct_b);
int test_my_struct_print(p_s_my_struct my_struct);
*/

int main(void)
{
    int errors = 0;
    p_s_my_struct my_struct = my_struct_alloc();

    errors += test_my_struct_alloc(my_struct);
    errors += test_my_struct_default_init(my_struct);
    errors += test_my_struct_randoms_init(my_struct);

    p_s_my_struct my_struct_dest = my_struct_alloc();

    errors += test_my_struct_copy(my_struct, my_struct_dest);

    my_struct_free(my_struct_dest);

    if (errors > 0)
    {
        printf("%d errors :c", errors);
    }

    my_struct_free(my_struct);

    return 0;
}

int test_my_struct_alloc(p_s_my_struct my_struct)
{
    if (my_struct == NULL)
        return 1;

    return 0;
}

int test_my_struct_default_init(p_s_my_struct my_struct)
{
    my_struct_default_init(my_struct);
    if (my_struct->number != 0 || my_struct->text != NULL)
    {
        return 1;
    }

    return 0;
}

int test_my_struct_randoms_init(p_s_my_struct my_struct)
{
    my_struct_randoms_init(my_struct);
    if (my_struct->number == 0 || my_struct->text == NULL)
    {
        return 1;
    }

    return 0;
}

int test_my_struct_copy(p_s_my_struct p_src, p_s_my_struct p_dest)
{
    my_struct_copy(p_src, p_dest);
    if (p_src->number != p_dest->number)
    {
        return 1;
    }
    return 0;
}
