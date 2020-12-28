//Andrew Decrem
//CSE320
//Project 5
#include <stdio.h>
#include <string.h>
#include "/user/cse320/Projects/project05.support.h"

int convert(const char ch[], int base, int* add)
{
 if (base > 36){
  return 0;
 }
 if (base < 2){
  return 0;
 }
 int value = 0;
 int negative = 0;
 *add = 0;
 int i = 0;
 while(ch[i] != 0){

  if(ch[i] == ' '){
    return 1;
  }
  else if (ch[i] == '\n'){
    return 1;
  }
  else if (ch[i] == '\t'){
    return 1;
  }
  else if (ch[i] == '-'){
    if (value == 1){
      return 1;
    }
    else{
      negative = 1;
    }
  }
  else if (ch[i] == '+'){
    if (value == 1){
      return 1;
    }
  }
  else if ((ch[i] >= '0') && (ch[i] <= '9')){
    int temp  = (ch[i] - '0');
    if (temp >= base){
      if(value == 0){
        return 0;
      }
      break;
    }
    value = 1;
    *add = (base * (*add)) + temp;
  }
  else if((ch[i] >= 'a') && (ch[i] <= 'z')){
    int temp = ((ch[i]-'a')+10);
    if (temp >= base){
      if(value == 0){
        return 0;
      }
      break;
    }
    value = 1;
    *add = (base * (*add)) + temp;
  }
  else{
    if(value == 0){
      return 0;
    }
    return 1;
  }
  i++;
 }
 if (negative  == 1){
  *add = 0-(*add);
 }
 return 1;
}
