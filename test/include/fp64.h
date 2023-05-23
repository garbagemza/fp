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

#ifndef __FP64__
#define __FP64__ 1

#include <stdint.h>

struct fp64 {
  int64_t mantissa;
  int64_t exponent;
};


// Sums 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_add(struct fp64* lhs, struct fp64* rhs, struct fp64* output);

// Subtracts 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_sub(struct fp64* lhs, struct fp64* rhs, struct fp64* output);

// Multiplies 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_mul(struct fp64* lhs, struct fp64* rhs, struct fp64* output);

// Divides 2 floating point values and rewrites the result into output
// The return value is 0
//
uint32_t fp64_div(struct fp64* lhs, struct fp64* rhs, struct fp64* output);

// Compares 2 floating point values and returns true whether lhs
// value is bigger or equal than rhs value.
//
int32_t fp64_cmp_ge(struct fp64* lhs, struct fp64* rhs);

#endif // !__FP64__

