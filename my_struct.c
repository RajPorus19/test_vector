#include "random.h"
#include "my_struct.h"

p_s_my_struct my_struct_alloc()
{
    p_s_my_struct my_struct = malloc(sizeof(s_my_struct));
    return my_struct;
}
void my_struct_free(p_s_my_struct p_vector)
{
    free(p_vector->text);
    free(p_vector);
}
void my_struct_default_init(p_s_my_struct p_vector)
{
    p_vector->number = 0;
    p_vector->text = NULL;
}
void my_struct_randoms_init(p_s_my_struct p_vector)
{
    size_t text_size = random_size_t(1, 10);
    p_vector->text = malloc(sizeof(unsigned char) * text_size);
    random_init_string(p_vector->text, text_size);
    p_vector->number = random_double(1, 100);
}
void my_struct_reset_to_default(p_s_my_struct p_vector)
{
    if (p_vector->text != NULL)
    {
        free(p_vector->text);
        p_vector->text = NULL;
    }
    p_vector->number = 0;
}
void my_struct_copy(p_s_my_struct p_dest, p_s_my_struct p_src)
{
    p_dest->number = p_src->number;
    p_dest->text = realloc(p_dest->text, sizeof(p_src->text));
    for (size_t i = 0; p_src->text[i] != '\0'; i++)
    {
        p_dest->text[i] = p_src->text[i];
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

void my_struct_print(p_s_my_struct p_vector)
{
    printf("%f\n", p_vector->number);
    printf("%s\n", p_vector->text);
}