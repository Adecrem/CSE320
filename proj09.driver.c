#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"

int main()
{
  //Negate a negative number
  int num1  = -10;
  printf("\nNegate start: %d: %d\n", num1, negate(num1));
  //negate zero
  num1 = 0;
  printf("Negate start: %d: %d\n", num1, negate(num1));
  //negate positive
  num1 = 10;
  printf("Negate start: %d: %d\n", num1, negate(num1));
  //negate smallest number
  num1 = -2147483648;
  printf("Negate start %d: %x\n", num1, negate(num1));
  //negate largest number
  num1 = 2147483647;
  printf("Negate start %d: %d\n", num1, negate(num1));

  printf("\n");
  //absolute value of negative
  num1 = -10;
  printf("Absolute value of %d: %d\n", num1, absolute(num1));
  //absolute value of zero
  num1 = 0;
  printf("Absolute value of %d: %d\n", num1, absolute(num1));
  //Absolute value of positive
  num1 = 10;
  printf("Absolute value of %d: %d\n", num1, absolute(num1));
  //absolute value of smallest
  num1 = -2147483648;
  printf("Absolute value of %d: %x\n", num1, absolute(num1));
  //absolute value of largest
  num1 = 2147483647;
  printf("Absolute value of %d: %d\n", num1, absolute(num1));

  //add two positive
  num1 = 1;
  int num2 = 5;
  printf("%d + %d = %d\n", num1, num2, add(num1, num2));
  //add two negative
  num1 = -12;
  num2 = -10;

  printf("%d + %d = %d\n", num1, num2, add(num1, num2));
  //add largest and number
  num1 = 2147483647;
  num2 = 10;
  printf("%d + %d = %0x\n", num1, num2, add(num1, num2));
  //subtract two positive
  num1 = 12;
  num2 = 10;
  printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
  //subtract positive and negative
  num1 = 5;
  num2 = -10;
  printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
  //subtract negative and positive
  num1 = -10;
  num2 = 5;
  printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
  //subtract two negative
  num1 = -5;
  num2 = -10;
  printf("%d - %d = %d\n", num1, num2, sub(num1, num2));
  //subtract smallest and positive
  num1 = -214783647;
  num2 = 10;
  printf("%d - %d = %0x\n", num1, num2, sub(num1, num2));
  //subtract positive and smallest
  num1 = 10;
  num2 = -214783647;
  printf("%d - %d = %0x\n", num1, num2, sub(num1, num2));

  //multiply two positive
  num1 = 5;
  num2 = 5;
  printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
  //multiply negative and positive
  num1 = -5;
  num2 = 10;
  printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
  //multiply by zero
  num1 = 5;
  num2 = 0;
  printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
  //multiply negative by zero
  num1 = -1;
  num2 = 0;
  printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
  //multiply two negative
  num1 = -10;
  num2 = -10;
  printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
  //multiply two zero
  num1 = 0;
  num2 = 0;
  printf("%d * %d = %d\n", num1, num2, mul(num1, num2));
  //multiply largest and positive
  num1 = 2147483647;
  num2 = 10;
  printf("%d * %d = %x\n", num1, num2, mul(num1, num2));

  printf("\n");
  //divide two positive
  num1 = 10;
  num2 = 10;
  printf("%d / %d = %d\n", num1, num2, divide(num1, num2));
  //divide two positive largest first
  num1 = 10;
  num2 = 8;
  printf("%d / %d = %d\n", num1, num2, divide(num1, num2));
  //divide positive by negative
  num1 = 15;
  num2 = -5;
  printf("%d / %d = %d\n", num1, num2, divide(num1, num2));
  //divide larger negative by positive
  num1 = -10;
  num2 = 5;
  printf("%d / %d = %d\n", num1, num2, divide(num1, num2));
  //divide two negatives
  num1 = -1;
  num2 = -1;
  printf("%d / %d = %d\n", num1, num2, divide(num1, num2));
  //divide positive by 0 error
  num1 = 1;
  num2 = 0;
  printf("%d / %d = %0x\n", num1, num2, divide(num1, num2));

  //power two positive
  num1 = 3;
  num2 = 5;
  printf("%d to the power of %d is %d\n", num1, num2, power(num1, num2));
  //power two positive error
  num1 = 10;
  num2 = 100;
  printf("%d to the power of %d is %d\n", num1, num2, power(num1, num2));
  //power positive negative
  num1 = 2;
  num2 = -5;
  printf("%d to the power of %d is %d\n", num1, num2, power(num1, num2));
  //power positive negative, negative base
  num1 = -3;
  num2 = 2;
  printf("%d to the power of %d is %d\n", num1, num2, power(num1, num2));
  //power two negative
  num1 = -2;
  num2 = -2;
  printf("%d to the power of %d is the %d\n", num1, num2, power(num1, num2));
  //factorial negative
  num1 = -10;
  printf("%d! = %0x\n", num1, factorial(num1));
  //factorial 0
  num1 = 0;
  printf("%d! = %d\n", num1, factorial(num1));
  //factorial positive
  num1 = 10;
  printf("%d! = %d\n", num1, factorial(num1));

  printf("\n");
  
}
