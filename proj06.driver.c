//Project 6
//CSE 320
//Author: Andrew Decrem
#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"
int main(){
  float inf = get_infinity();
  float nan = get_nan();
  float max_norm = get_max_normal();
  float min_norm = get_min_normal();
  float max_denorm = get_max_denormal();
  float min_denorm = get_min_denormal();

  union ieee_single A;
  union ieee_single B;
  union ieee_single C;
  union ieee_single D;
  union ieee_single E;
  union ieee_single F;
  A.frep = inf;
  B.frep = nan;
  C.frep = max_norm;
  D.frep = min_norm;
  E.frep = max_denorm;
  F.frep = min_denorm;

  printf("get_infinity: %.02f\n", A.frep);
  printf("get_nan: %.02f\n", B.frep);
  printf("get_max_normal: %.02f\n", C.frep);
  printf("get_min_normal: %.02f\n", D.frep);
  printf("get_max_denormal: %.02f\n", E.frep);
  printf("get_min_denormal: %.02f\n", F.frep);


  float negative = -1;
  int neg = is_negative(negative);
  printf("yes negative: %d\n", neg);


  float positive = 1;
  int neg1 = is_negative(positive);
  printf("no negative: %d\n", neg1);


  float infin = get_infinity();
  int is_inf = is_infinity(infin);
  printf("yes infinity: %d\n", is_inf);

  float no_infin = 1.0;
  int is_inf1 = is_infinity(no_infin);
  printf("no infinity: %d\n", is_inf1);


  float a_nan = get_nan();
  int is_na = is_nan(a_nan);
  printf("yes nan: %d\n", is_na);


  float not_nan = 10.0;
  int is_na1 = is_nan(not_nan);
  printf("no nan %d\n", is_na1);


  float z = 0.0;
  int zero = is_zero(z);
  printf("Zero: %d\n", zero);

  float not_z = 1.0;
  int zero1 = is_zero(not_z);
  printf("no Zero: %d\n", zero1);


  union ieee_single denormy;
  denormy.irep = 0x00000001;
  int denorm = is_denormal(denormy.frep);
  printf("Denormal: %d\n", denorm);

  float notdenum = 2;
  int denorm1 = is_denormal(notdenum);
  printf("no Denormal: %d\n", denorm1);

  float pos = 1;
  float negated = negate(pos);
  printf("negative: %f\n", negated);


  float make_absolute = - 1;
  float abs = absolute(make_absolute);
  printf("Absolute: %f\n", abs);

}
