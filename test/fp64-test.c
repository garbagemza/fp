#include <stdio.h>
#include "include/fp64.h"


int main(int argc, char *argv[])
{
  struct fp64 a = {3, -2};
  struct fp64 b = {3, 2};
  struct fp64 out;
  
  fp64_add(&a, &b, &out);

  printf("The sum is: %lld e %lld\n", out.mantissa, out.exponent);

  fp64_sub(&a, &b, &out);

  printf("The subtraction is: %lld e %lld\n", out.mantissa, out.exponent);

  int32_t bigger = fp64_cmp_ge(&a, &b);
  printf("a is bigger than b?: %d\n", bigger);

  int32_t bigger2 = fp64_cmp_ge(&b, &a);
  printf("b is bigger than a?: %d\n", bigger2);

  fp64_mul(&a, &b, &out);
  printf("The multiplication is %lld e %lld\n", out.mantissa, out.exponent);

  fp64_div(&a, &b, &out);
  printf("The division is %lld e %lld\n", out.mantissa, out.exponent);

  return 0;
}

