/***********************
Author: Andrew Decrem

CSE 320 Project 8

This project reads in a file
and outputs
Total number of characters
Number of newline characters
Number of whitespace characters

Alot of my code was inspired by the examples, especially example 17
Piazza also was a big impact in deciding how I would order my code
************************/  


      .global main


      .text

main: push  {lr}

      mov r4, #0 @Initialize the total number of character count
      mov r5, #0 @Initialize the total number of newline count
      mov r6, #0 @Initialize the total number of whitespace count
      mov r7, #0 @Initialize the total number of arithmetic count
      mov r8, #0 @Initialize the total number of decimal count
      mov r9, #0 @Initialize the total number of hexadecimal count
      mov r10, #0 @Initialize the total number of letters count


@for total amount of characters
loop: bl  getchar @A loop to read the characters
      cmp r0, #-1 @Return once end of line is reached (Thank you Professor)
      beq end  @When found ending exit
      bl  putchar @One character
      add r4, r4, #1 @Incrementing count


@For newlines
ifNewLine:  cmp r0, #0xA @compare return to newline
            bne endifNewLine @If not found then keep moving

thenNewLine:  add r5, r5, #1 @add newlines

endifNewLine:

@for whitespaces


ifWhiteLine: cmp r0, #0x20 @compare return to whitespace
              beq thenWhiteLine @when found go to then
              cmp r0, #0x09 @count for tab
              beq thenWhiteLine
              cmp r0, #0xA @count for newline
              bne endifWhiteLine
thenWhiteLine:  add r6, r6, #1 @add to count

endifWhiteLine:

@for arithemtic characters
ifArithmatic: cmp r0, #0x2f @count for '/'
              beq thenArithmatic @go to then
              cmp r0, #0x2A @count for '*'
              beq thenArithmatic @go to then
              cmp r0, #0x2D @count for '-'
              beq thenArithmatic @go to then
              cmp r0, #0x2B @count for '+'
              bne endifArithmatic

thenArithmatic: add r7, r7, #1 @add to count

endifArithmatic:

@for decimals
ifDecimal:  cmp r0, #0x39 @for 9
            bgt endifDecimal
            cmp r0, #0x30 @for 0
            blt endifDecimal

thenDecimal:  add r8, r8, #1 @add to decimal
              add r9, r9, #1 @add to hexadecimal

endifDecimal:

@for hexadecimal lower letters
ifHexLower: cmp r0, #0x66 @ for 'f'
            bgt endifHexLower
            cmp r0, #0x61 @for 'a'
            blt endifHexLower
thenHexLower: add r9, r9, #1

endifHexLower:


@for hexadecimal upper letters
ifHexUpper: cmp r0, #0x46 @for 'F'
            bgt endifHexUpper
            cmp r0, #0x41 @for 'A'
            blt endifHexUpper
thenHexUpper: add r9, r9, #1 @adding

endifHexUpper:


ifLetLower: cmp r0, #0x7A @for 'z'
            bgt endifLetLower
            cmp r0, #0x61 @for 'a'
            blt endifLetLower
thenLetLower: add r10,r10,#1

endifLetLower:

ifLetUpper:  cmp r0, #0x5A @for 'z'
            bgt endifLetUpper
            cmp r0, #0x41 @for 'A'
            blt endifLetUpper
thenLetUpper:  add r10,r10,#1

endifLetUpper: b    loop @to the top of the loop

end:

              ldr r0, =fmt1 @formatting
              mov r1, r4 @character count
              bl  printf @printing

              ldr r0, =fmt2 @formatting
              mov r1, r5 @character count
              bl  printf @printing

              ldr r0, =fmt3 @formatting
              mov r1, r6 @character count
              bl  printf @printing

              ldr r0, =fmt4 @formatting
              mov r1, r7 @character count
              bl  printf @printing

              ldr r0, =fmt5 @formatting
              mov r1, r8 @character count
              bl  printf @printing

              ldr r0, =fmt6 @formatting
              mov r1, r9 @character count
              bl  printf @printing
                
              ldr r0, =fmt7 @formatting
              mov r1, r10 @character count 
              bl  printf @printing


              pop {lr}
              bx  lr


fmt1: .asciz "\nNum characters: %d\n"
fmt2: .asciz "Num newLines: %d\n"
fmt3: .asciz "Num whitespace characters: %d\n"
fmt4: .asciz "Numb arithmetic operators: %d\n"
fmt5: .asciz "Num decimal digits: %d\n"
fmt6: .asciz "Num hexadecimal digits: %d\n"
fmt7: .asciz "Num letters: %d\n"


