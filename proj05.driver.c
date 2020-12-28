#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"
#include "/user/cse320/lib/bitlib.h"

int main(int argc, const char * argv[]){

  char test1[] = "  +aaA";
  int base0 = 16;
  int num0 = 0;
  int T1 = convert(&test1[0], base0, &num0);
  if(T1 == 1){
    printf("Value: %s base %d\n", test1, base0);
    printf("Decimal: %d Hexadecimal: %08x\n\n", num0, num0);
  }


  char test2[] = "  -aaA";
  int base1 = 16;
  int num1 = 0;
  int T2 = convert(&test2[0], base1, &num1);
  if (T2 == 1){
    printf("Value: %s base1 %d\n", test2, base1);
    printf("Decimal: %d Hexadecimal: %08\n\n", num1, num1);
  }



  char test3[] = "100!";
  int base2 = 2;
  int num2 = 0;
  int T3 = convert(&test3[0], base2, &num2);
  if (T3 == 1){
    printf("Value: %s base2 %d\n", test3, base2);
    printf("Decimal: %d Hexadecimal: %08\n\n", num2, num2);
  }
  char test4[] = "abcd";
  int base3 = 16;
  int num3 = 0;
  int T4 = convert(&test4[0], base3, &num3);
  if (T4 == 1){
    printf("Value: %s base3 %d\n", test4, base3);
    printf("Decimal: %d Hexadecimal: %08\n\n", num3, num3);
  }

  char test5[] = "zZ";
  int base4 = 36;
  int num4 = 0;
  int T5 = convert(&test5[0], base4, &num4);
  if (T5 == 1){
    printf("Value: %s base4 %d\n", test5, base4);
    printf("Decimal: %d Hexadecimal: %08\n\n", num4, num4);
  }

  char test6[] = "\n \t abcd";
  int base5 = 16;
  int num5 = 0;
  int T6 = convert(&test6[0], base5, &num5);
  if (T6 == 1){
    printf("Value: %s base5 %d\n", test6, base5);
    printf("Decimal: %d Hexadecimal: %08\n\n", num5, num5);
  }

  char test7[] = "  ab89 -+54";
  int base6 = 16;
  int num6 = 0;
  int T7 = convert(&test7[0], base6, &num6);
  if (T7 == 1){
    printf("Value: %s base6 %d\n", test7, base6);
    printf("Decimal: %d Hexadecimal: %08\n\n", num6, num6);
  }

  char test8[] = "ab89-&54";
  int base7 = 36;
  int num7 = 0;
  int T8 = convert(&test8[0], base7, &num7);
  if (T8 == 1){
    printf("Value: %s base7 %d\n", test8, base7);
    printf("Decimal: %d Hexadecimal: %08\n\n", num7, num7);
  }

  char test9[] = "1023";
  int base8 = 10;
  int num8 = 0;
  int T9 = convert(&test9[0], base8, &num8);
  if (T9 == 1){
    printf("Value: %s base8 %d\n", test9, base8);
    printf("Decimal: %d Hexadecimal: %08\n\n", num8, num8);
  }

  char test10[] = "2378DE";
  int base9 = 16;
  int num9 = 0;
  int T10 = convert(&test10[0], base9, &num9);
  if (T10 == 1){
    printf("Value: %s base9 %d\n", test10, base9);
    printf("Decimal: %d Hexadecimal: %08\n\n", num9,num9);
  }

  char test11[] = "1YZ";
  int base10 = 36;
  int num10 = 0;
  int T11 = convert(&test11[0], base10, &num10);
  if (T11 == 1){
    printf("Value: %s base10 %d\n", test11, base10);
    printf("Decimal: %d Hexadecimal: %08\n\n", num10, num10);
  }

  char test12[] = "  ";
  int base11 = 10;
  int num11 = 0;
  int T12 = convert(&test12[0], base11, &num11);
  if (T12 == 1){
    printf("Value: %s base11 %d\n", test12, base11);
    printf("Decimal: %d Hexadecimal: %08\n\n", num11, num11);
  } 

  char test13[] = "WXYZ";
  int base12 = 10;
  int num12 = 0;
  int T13 = convert(&test13[0], base12, &num12);
  if (T13 == 1){
    printf("Value: %s base12 %d\n", test13, base12);
    printf("Decimal: %d Hexadecimal: %08\n\n", num12, num12);
  }

  char test14[] = "37 ";
  int base13 = 8;
  int num13 = 0;
  int T14 = convert(&test14[0], base13, &num13);
  if (T14 == 1){
    printf("Value: %s base13 %d\n", test14, base13);
    printf("Decimal: %d Hexadecimal: %0\n\n", num13, num13);
  }

  return 0;
}
