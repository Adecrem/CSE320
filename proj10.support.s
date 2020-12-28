/********************
Name: Andrew Decrem
Project 10

Project to take in an array of char's
and run them through a variation of functions
Length: Return the number of characters in the string.
Append: Append contents of a string to another string.
Duplicate: Return address of duplicate string
Compare: Compares two strings
  if the strings are equal it will return 0
  if the first is less than the second it will return negative
  if the first is greater than the second it will return positive
********************/


  .global length
  .global copy
  .global append
  .global duplicate
  .global compare
  .text
/****************************
Length
prints the length of a string 
input of a string
output number of characters in the string
*****************************/

length:
  push {r4, lr}
  mov r4, #0 @start character count at 0

lloop:

  ldrb r3, [r0] @load r0 byte to r3
  cmp r3, #0 @Check if end of the character is None
  beq lend @When it hits 0 exit loop
  add r0, r0, #1 @Byte increment
  add r4, r4, #1 @Chatacter count increment
  b lloop

lend:
  mov r0, r4 @return the count
  pop {r4, lr}
  bx lr


/**********************
Copy
Copies a string
Inputs a string and a destiniation
no output
***********************/

copy:
  push {lr}

cloop:
  ldrb r3, [r1] @load r1 byte to r3
  cmp r3, #0 @Compare return to 0
  beq cend @0 found exit
  strb r3, [r0] @r3 stored in r0
  add r1, r1, #1 @next byte
  add r0, r0, #1 @next byte
  b cloop

cend:
  pop {lr}
  bx lr


/*********************
Append
Appends one string to the end of antoher
input destination and original string
*********************/

append:
  push {r4, r5, lr}
  mov r4, r0 @Move r0 to r4
  mov r5, r1 @Move r1 to r5
  bl length @Branch and find length of destination
  add r0, r4, r0 @last char of destination
  mov r1, r5 @r5 to r1
  bl copy @calling copy
  pop {r4, r5, lr}
  bx lr


/********************
Duplicate
Duplicates a string to a new address
input a string
returns duplicated string at new address
*********************/

duplicate:
  push {r4, r5, lr}
  mov r4, r0 @r0 to r4
  bl length @branch and find length of destination
  add r0, r0, #1 @adding one to string
  bl malloc @allocating size
  mov r5, r0 @malloc to r5
  mov r1, r4 @source to r1
  bl copy @copy
  mov r0, r5 @malloc to r0
  pop {r4, r5, lr}
  bx lr

/**********************
Compare
Compares two strings
inputs two strings
return depends on output
if 1 > 2 returns positive integer
if 1 < 2 returns negative integer
if 1 == 2 returns 0
**********************/
compare:
  push {r4, r5, r6, lr}

compare_loop:
  ldrb r4, [r0] @r0 byte to r4
  ldrb r5, [r1] @r1 byte to r5
  sub r6, r4, r5 @r4 - r5
  cmp r4, #0 @return compared to 0
  beq compare_end @found 0 then exit
  cmp r5, #0 @compare return to 0
  beq compare_end @found 0 then exit
  cmp r6, #0 @compare return to 0
  beq compare_end @found 0 then exit
  add r0, r0, #1 @next byte
  add r1, r1, #1 @next byte
  b compare_loop

compare_end:
  mov r0, r6 @r6 to 0
  pop {r4, r5, r6, lr}
  bx lr
