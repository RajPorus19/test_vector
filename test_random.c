#include "random.h"
#include <stdio.h>

int test_random_double(double a, double b);
int test_random_float(float a, float b);
int test_random_size_t(size_t a, size_t b);
int test_random_int(int a, int b);
int test_random_uchar(unsigned char a, unsigned char b);
int test_random_string(size_t n);

int main(void)
{
  int counter = 0;
  double a = 40;
  double b = 60;
  // run tests
  counter += test_random_double(a, b);
  counter += test_random_float((float)a, (float)b);
  counter += test_random_size_t((size_t)a, (size_t)b);
  counter += test_random_int((int)a, (int)b);
  counter += test_random_uchar((unsigned int)a, (unsigned int)b);
  counter += test_random_string(6);
  // print result
  if (counter == 0)
    printf("All tests have passed successfuly ! :) \n");
  else
    printf("%d tests have failed :(  \n", counter);
  return 0;
};

int test_random_double(double a, double b)
{
  double res = random_double(a, b);
  if ((res > a) && (res < b))
    return 0;
  return 1;
}

int test_random_float(float a, float b)
{
  float res = random_double(a, b);
  if ((res > a) && (res < b))
    return 0;
  return 1;
}

int test_random_size_t(size_t a, size_t b)
{
  float res = random_double(a, b);
  if ((res > a) && (res < b))
    return 0;
  return 1;
}

int test_random_int(int a, int b)
{
  float res = random_double(a, b);
  if ((res > a) && (res < b))
    return 0;
  return 1;
}

int test_random_uchar(unsigned char a, unsigned char b)
{
  float res = random_double(a, b);
  if ((res > a) && (res < b))
    return 0;
  return 1;
}

int test_random_string(size_t n)
{
  int fails = 0;
  unsigned char *c = malloc(n * sizeof(unsigned char));
  random_init_string(c, n);
  for (size_t i = 0; i < n; i++)
  {
    if ('A' > c[i] && c[i] > 'Z')
      fails++;
  }
  free(c);
  if (fails == 0)
    return 0;
  return 1;
}
