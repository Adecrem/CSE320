//Project 6
//CSE 320
//Author: Andrew Decrem
#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"
//doc.ic.ac.uk/~eedwards/compsys/float/nan.html
//^ used for help understanding values

float get_infinity()
{
  float infinity = 0x7f800000;
  return infinity;
}

float get_nan()
{
  float nan = 0x7f800001;
  return nan;
}

float get_max_normal()
{
  float max_normal = 0x7f7fffff;
  return max_normal;
}

float get_min_normal()
{
  float min_normal = 0x00800000;
  return min_normal;
}

float get_max_denormal()
{
  float max_denormal = 0x007fffff;
  return max_denormal;

}

float get_min_denormal()
{
  float min_denormal = 0x00000001;
  return min_denormal;
}

int is_negative(float num)
{
  int sign;
  union ieee_single n;
  n.frep = num;
  sign = n.irep >> 31;
  if (sign == 0x00000000){
    return 0;
  }else{
    return 1;
}
return 0;
}

int is_infinity(float num)
{
  union ieee_single n;
  n.frep = num;

  if (n.frep == 0x7f800000){
    return 1;
  }
  return 0;
}

int is_nan(float num)
{
  union ieee_single n;
  n.frep = num;
  
  if (n.frep == 0x7f800001){
    return 1;
  }

return 0;
}

int is_zero(float num)
{
  union ieee_single n;
  n.frep = num;
  if (n.frep == 0x00000000)
  {
    return 1;
  }else{
    return 0;
}
}
int is_denormal(float num)
{
  union ieee_single n;
  n.frep = num;

  if (n.frep == 0x00000001 ||  n.frep == 0x7f7fffff){
    return 1;
  }
  return 0;
}

float negate( float num ){
  union ieee_single n;
  n.frep = num;
  if (n.frep > 0x00000000)
  {
    n.irep = n.irep * -1;
  }
  return n.frep;
}

float absolute( float num ){
  union ieee_single n;

  n.frep = num;
  
  if (n.frep <= 0x00000000){
    n.frep = n.frep * -1;
  }
  
  return n.frep;
}

//union ieee_single
//{
//  float frep;
//  unsigned int irep;
//};

