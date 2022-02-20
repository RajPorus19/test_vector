#include <stdio.h>
#include <string.h>
#include "random.h"
#include "my_struct.h"

p_s_my_struct my_struct_alloc()
{
    p_s_my_struct my_struct = malloc(sizeof(s_my_struct));
    my_struct_default_init(my_struct);
    return my_struct;
}
void my_struct_free(p_s_my_struct p_my_struct)
{
    free(p_my_struct->text);
    free(p_my_struct);
    p_my_struct = NULL;
}
void my_struct_default_init(p_s_my_struct p_my_struct)
{
    p_my_struct->number = 0;
    p_my_struct->text = NULL;
}
void my_struct_randoms_init(p_s_my_struct p_my_struct)
{
    size_t text_size = random_size_t(3, 5);
    if (p_my_struct->text == NULL)
    {
        p_my_struct->text = malloc(sizeof(unsigned char) * text_size);
    }
    else
    {
        p_my_struct->text = realloc(p_my_struct->text, sizeof(unsigned char) * text_size);
    }
    random_init_string(p_my_struct->text, text_size);
    p_my_struct->number = random_double(1, 100);
}
void my_struct_reset_to_default(p_s_my_struct p_my_struct)
{
    if (p_my_struct->text != NULL)
    {
        free(p_my_struct->text);
        p_my_struct->text = NULL;
    }
    p_my_struct->number = 0;
}
void my_struct_copy(p_s_my_struct p_src, p_s_my_struct p_dest)
{
    p_dest->number = p_src->number;
    if (p_src->text == NULL)
    {
        p_dest->text = NULL;
    }
    else
    {
        p_dest->text = malloc(sizeof(p_src->text));
        strcpy((char *)p_dest->text, (char *)p_src->text);
    }
}
int my_struct_cmp(p_s_my_struct p_vector_a, p_s_my_struct p_vector_b)
{
    if (p_vector_a->number < p_vector_b->number)
    {
        return 1;
    }
    else if (p_vector_a->number > p_vector_b->number)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void my_struct_print(p_s_my_struct p_my_struct)
{
    printf("%f\n", p_my_struct->number);
    if (p_my_struct->text == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        printf("%s\n", p_my_struct->text);
    }
}
