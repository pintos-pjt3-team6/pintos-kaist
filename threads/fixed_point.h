#include <stdint.h>
#define F (1 << 14)     //fixed point 1 (in 17.14 format)
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1 << 31))

/* x and y denote fixed_point numbers in 17.14 format
*  n is an integer 
*  int = integer
*  fp = fixed point numbers
*/

/* Prototypes */
int int_to_fp(int n);
int fp_to_int_round(int x);
int fp_to_int(int x);
int add_fp(int x, int y);
int add_mixed(int x, int n);
int sub_fp(int x, int y);
int sub_mixed(int x, int n);
int mult_fp(int x, int y);
int mult_mixed(int x, int y);
int div_fp(int x, int y);
int div_mixed(int x, int n);

/* convert int to fp */
int int_to_fp (int n) {
  return n * F;
}

/* convert fp to int (rounding toward zero) */
int fp_to_int (int x) {
  return x / F;
}

/* convert fp to int (rounding to nearest int)  */
int fp_to_int_round (int x) {
  if (x >= 0) return (x + F / 2) / F;
  else return (x - F / 2) / F;
}

/* fp + fp */
int add_fp (int x, int y) {
  return x + y;
}

/* fp - fp */
int sub_fp (int x, int y) {
  return x - y;
}

/*  */
int add_mixed (int x, int n) {
  return x + n * F;
}

int sub_mixed (int x, int n) {
  return x - n * F;
}

int mult_fp (int x, int y) {
  return ((int64_t) (x)) * y / F;
}

int mult_mixed (int x, int n) {
  return x * n ;
}

int div_fp (int x, int y) {
  return ((int64_t) (x)) * F / y;
}

int div_mixed (int x, int n) {
  return x / n;
}