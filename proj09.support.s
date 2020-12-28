/********************************
   Andrew Decrem
   CSE 320
   Computer project #9
********************************/
  .global negate
  .global absolute
  .global add
  .global sub
  .global mul
  .global divide
  .global power
  .global factorial
  .text
/*-----------------------------
  Negate:
  Negates a number given
  Takes in number
  Returns negated number

------------------------------*/
negate:
  push {r4, lr}
  mov r4, r0
  rsb r0, r4, #0
  b donesingle

/*-----------------------
  absolute
  returns the absolute value of a number
  Takes in a number
  Returns the absolute value of it
------------------------*/
absolute:
  push {r4, lr}
  mov r4, r0
  cmp r4, #0
  bge donesingle
  rsb r0, r4, #0
  b donesingle

/*--------------------
  add
  adds two numbers together
  takes in two numbers
  returns the sum of them
---------------------*/
add:
  push {r4, r5, lr}
  mov r4, r0
  mov r5, r1
  adds r0, r4, r5
  bvs overflow
  bvc donedouble
/*--------------------
  sub
  subtracts two numbers
  takes in two numbers
  returns the subtraction of the two
---------------------*/
sub:
  push {r4, r5, lr}
  mov r4, r0
  mov r5, r1
  subs r0, r4, r5
  bvs overflow
  bvc donedouble
/*---------------------
  mul
  multiplies two numbers
  takes in two numbers
  returns the product of the two
----------------------*/
mul:
  push {r4, r5, lr}
  smull r4, r5, r0, r1
  mov r0, r4
  asr r4, #31
  cmp r4, r5
  bne overflow
  bvc donedouble
/*-----------------
  divide
  divides two numbers
  takes in two numbers
  returns the division of the two
------------------*/
divide:
  push {r4, r5, lr}
  mov r4, r0
  mov r5, r1
  cmp r5, #0
  beq overflow
  sdiv r0, r4, r5
  bvc donedouble
/*-------------
  power
  returns a number to a power of another
  takes in two numbers
  returns number 1 to the power of number 2
--------------*/
power:
  push {r4, r5, lr}
  mov r4, r0
  mov r5, r1
  cmp r5, #0
  blt overflow
  beq pow_done1
  mov r0, r4

power_loop:
  cmp r5, #1
  beq donedouble
  mov r1, r4
  bl mul
  add r5, r5, #-1
  b power_loop

factorial:
  push {r4, lr}
  mov r4, r0
  cmp r4, #0
  beq fac_done1
  blt fac_error
  mov r0, r4

loop:
  cmp r4, #1
  beq donesingle
  add r4, r4, #-1
  mov r1, r4
  bl mul
  b loop

overflow:
  mov r0, #0x80000000
  b donedouble

donesingle:
  pop {r4, lr}
  bx lr

donedouble:
  pop {r4, r5, lr}
  bx lr

pow_done1:
  mov r0, #1
  pop {r4, r5, lr}
  bx lr

fac_error:
  mov r0, #0x80000000
  pop {r4, lr}
  bx lr

fac_done1:
  mov r0, #1
  pop {r4, lr}
  bx lr
