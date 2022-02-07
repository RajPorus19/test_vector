#include <stdlib.h>
#ifndef RANDOM_H_
#define RANDOM_H_

double random_double(double a, double b);
float random_float(float a, float b);
size_t random_size_t(size_t a, size_t b);
int random_int(int a, int b);
unsigned char random_uchar(unsigned char a, unsigned char b);
void random_init_string(unsigned char * c, size_t n);

#endif // RANDOM_H_
