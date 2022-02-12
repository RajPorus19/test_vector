#include "my_struct.h"

int main(int argc, char const *argv[])
{
    p_s_my_struct my_struct = my_struct_alloc();

    my_struct_randoms_init(my_struct);

    my_struct_print(my_struct);

    return 0;
}
