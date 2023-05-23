#include <stdint.h>
#include <stdio.h>

struct fp64 {
  int64_t mantissa;
  int64_t exponent;
};

int64_t fp64_min_exponent(struct fp64* lhs, struct fp64* rhs) {
  if (lhs->exponent <= rhs->exponent) {
    return lhs->exponent;
  } else {
    return rhs->exponent;
  }
}

struct fp64 fp64_callibrate(struct fp64* value, int64_t min_exponent) {

  struct fp64 result;
  result.mantissa = value->mantissa;
  result.exponent = value->exponent;

  while (result.exponent > min_exponent) {
    result.mantissa *= 10;
    result.exponent--;
  }
  return result;
}

// Sums 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_add(struct fp64* lhs, struct fp64* rhs, struct fp64* output) {
  int64_t min = fp64_min_exponent(lhs, rhs);
  struct fp64 lhs_copy = fp64_callibrate(lhs, min);
  struct fp64 rhs_copy = fp64_callibrate(rhs, min);
  output->mantissa = lhs_copy.mantissa + rhs_copy.mantissa;
  output->exponent = lhs_copy.exponent;
  return 0;
}

// Subtracts 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_sub(struct fp64* lhs, struct fp64* rhs, struct fp64* output) {
  int64_t min = fp64_min_exponent(lhs, rhs);
  struct fp64 lhs_copy = fp64_callibrate(lhs, min);
  struct fp64 rhs_copy = fp64_callibrate(rhs, min);
  output->mantissa = lhs_copy.mantissa - rhs_copy.mantissa;
  output->exponent = lhs_copy.exponent;
  return 0;
}

// Compares 2 floating point values and returns true whether lhs
// value is bigger or equal than rhs value.
//
int64_t fp64_cmp_ge(struct fp64* lhs, struct fp64* rhs) {
  int64_t min = fp64_min_exponent(lhs, rhs);
  struct fp64 lhs_copy = fp64_callibrate(lhs, min);
  struct fp64 rhs_copy = fp64_callibrate(rhs, min);
  return lhs_copy.mantissa >= rhs_copy.mantissa;
}

int main(int argc, char *argv[])
{
  struct fp64 a = {3, 2};
  struct fp64 b = {3, 2};
  struct fp64 out;
  
  fp64_add(&a, &b, &out);

  printf("The sum is: %lld e %lld\n", out.mantissa, out.exponent);

  fp64_sub(&a, &b, &out);

  printf("The subtraction is: %lld e %lld\n", out.mantissa, out.exponent);

  int64_t bigger = fp64_cmp_ge(&a, &b);
  printf("a is bigger than b?: %lld\n", bigger);

  int64_t bigger2 = fp64_cmp_ge(&b, &a);
  printf("b is bigger than a?: %lld\n", bigger2);

  return 0;
}
