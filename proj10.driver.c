#include <stdio.h>
#include "/user/cse320/Projects/project10.support.h"

int main()
{
  char num1[] = "AndrewDecrem";
  printf("\nNumber of characters in '%s': %d\n", num1, length(num1));

  char num2[] = "";
  printf("\nNumber of characters in an empty string '%s'> %d\n", num2, length(num2));

  char num3[30];
  copy(num3, num1);
  printf("\nCopied string: %s\n", num3);


  char num4[20] = "Andrew ";
  char num5[20] = "Decrem";
  append(num4, num5);
  printf("\nMy appended name %s\n", num4);

  printf("\nDuplicated my name %s\n", duplicate(num4));

  char empty[] = "";
  printf("\nDuplicated empty %s\n", duplicate(empty));

  printf("\nTwo equal string compared %d\n", compare(num1, num1));

  char first[20] = "Andrew";
  char second[20] = "Havdala Decrem";
  printf("\nCompare first < second %d\n", compare(first, second));

  printf("\nCompare first > second %d\n", compare(second, first));

  char empty2[20] = "";
  printf("\nCompare a full string and an empty one: %d\n", compare(empty2, first));
}
