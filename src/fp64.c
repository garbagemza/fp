/**
  * This is free and unencumbered software released into the public domain.
  *
  * Anyone is free to copy, modify, publish, use, compile, sell, or
  * distribute this software, either in source code form or as a compiled
  * binary, for any purpose, commercial or non-commercial, and by any
  * means.
  *
  * In jurisdictions that recognize copyright laws, the author or authors
  * of this software dedicate any and all copyright interest in the
  * software to the public domain. We make this dedication for the benefit
  * of the public at large and to the detriment of our heirs and
  * successors. We intend this dedication to be an overt act of
  * relinquishment in perpetuity of all present and future rights to this
  * software under copyright law.
  *
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  * OTHER DEALINGS IN THE SOFTWARE.
  *
  * For more information, please refer to <https://unlicense.org>
  **/

#include "fp64.h"

int64_t fp64_min_exponent(const struct fp64* lhs, const struct fp64* rhs);
struct fp64 fp64_callibrate(const struct fp64* value, int64_t min_exponent);

// Sums 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_add(const struct fp64* lhs, const struct fp64* rhs, struct fp64* output) {
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
uint32_t fp64_sub(const struct fp64* lhs, const struct fp64* rhs, struct fp64* output) {
  int64_t min = fp64_min_exponent(lhs, rhs);
  struct fp64 lhs_copy = fp64_callibrate(lhs, min);
  struct fp64 rhs_copy = fp64_callibrate(rhs, min);
  output->mantissa = lhs_copy.mantissa - rhs_copy.mantissa;
  output->exponent = lhs_copy.exponent;
  return 0;
}

// Multiplies 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_mul(const struct fp64* lhs, const struct fp64* rhs, struct fp64* output) {
  output->mantissa = lhs->mantissa * rhs->mantissa;
  output->exponent = lhs->exponent + rhs->exponent;
  return 0;
}

// Divides 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_div(const struct fp64* lhs, const struct fp64* rhs, struct fp64* output) {
  output->mantissa = lhs->mantissa / rhs->mantissa;
  output->exponent = lhs->exponent - rhs->exponent;
  return 0;
}

// Compares 2 floating point values and returns true whether lhs
// value is bigger or equal than rhs value.
//
int32_t fp64_cmp_ge(const struct fp64* lhs, const struct fp64* rhs) {
  int64_t min = fp64_min_exponent(lhs, rhs);
  struct fp64 lhs_copy = fp64_callibrate(lhs, min);
  struct fp64 rhs_copy = fp64_callibrate(rhs, min);
  return lhs_copy.mantissa >= rhs_copy.mantissa;
}

int64_t fp64_min_exponent(const struct fp64* lhs, const struct fp64* rhs) {
  if (lhs->exponent <= rhs->exponent) {
    return lhs->exponent;
  } else {
    return rhs->exponent;
  }
}

struct fp64 fp64_callibrate(const struct fp64* value, int64_t min_exponent) {
  struct fp64 result;
  result.mantissa = value->mantissa;
  result.exponent = value->exponent;
  while (result.exponent > min_exponent) {
    result.mantissa *= 10;
    result.exponent--;
  }
  return result;
}

