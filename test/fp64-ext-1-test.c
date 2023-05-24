#include <stdio.h>
#include "include/fp64-ext-1.h"


int main(int argc, char *argv[])
{
  struct fp64 val = {3, 2};
  struct fp64 percentage = {33333, -3};

  struct fp64 out = fp64_ext1_percentage(&val, &percentage);
  printf("The percentage is: %lld e %lld\n", out.mantissa, out.exponent);

  struct fp64 copy = fp64_ext1_copy(&val);
  printf("The copy is: %lld e %lld\n", copy.mantissa, copy.exponent);

  return 0;
}

