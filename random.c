#include "random.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned long seed = 0;

double random_double(double a, double b)
{
  seed++;
  srand(time(NULL) + seed);
  return rand() / (RAND_MAX / (b - a)) + a;
}

float random_float(float a, float b)
{
  return (float)random_double((double)a, (double)b);
}

size_t random_size_t(size_t a, size_t b)
{
  return (size_t)random_double((double)a, (double)b);
}

int random_int(int a, int b)
{
  return (int)random_double((double)a, (double)b);
}

unsigned char random_uchar(unsigned char a, unsigned char b)
{
  return (unsigned char)random_double((double)a, (double)b);
}

void random_init_string(unsigned char *c, size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    c[i] = random_uchar('A', 'Z');
  }
  c[n - 1] = '\0';
}
