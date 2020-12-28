/*******************************
  Andrew Decrem
  Project 11
  File headers inspired by pdf
*******************************/


/*******************************
search
locate and return pointer to a student
Args:
pointer to table of students
number to locate
pointer to pointer to student
return:
1 if located
0 if not
*******************************/
  .global search 
  .text
  .balign 4

search:
  push {r4, r5, r6, r7, r8, r9, r10, lr} @first push
  mov r10, r2 @10 to 2
  mov r4, r0 @for the table
  mov r5, r1 @search for number

  ldrh r6, [r0, #4] @count
  ldr r7, [r0, #8] @memory
  mov r8, #1 @counter

search_loop:
  cmp r6, r8 @compare the table
  blt end
  ldrh r9, [r7] @student id
  cmp r9, r5 @compare to id
  beq found @check if found
  cmp r9, r5 @compare
  bgt end
  add r8, r8, #1 @add to count
  add r7, r7, #44 @go to next student
  b search_loop

found:
  mov r0, #1
  str r7, [r2]
  pop {r4, r5, r6, r7, r8, r9, r10, lr}
  bx lr

end:
  mov r0, #0
  str r7, [r2]
  pop {r4, r5, r6, r7, r8, r9, r10, lr}
  bx lr


/************************************
delete
delete a student from table
args:
pointer to table
id of student
return:
1 if deleted 0 if not
*************************************/

    .global delete
    .data
X:  .word 0
    .text
    .balign 4

delete:
  push {r4, r5, r6, r7, r8, r9, r10, lr}
  mov r10, #44
  ldrh r6, [r0, #2] @count
  mov r4, r0 @table
  mov r5, r1 @student id
  ldr r2, =X 
  bl search

  mov r7, r0
  ldr r8, [r2]

  cmp r7, #0 @compare to 0
  beq delete_end @delete failed
  
  ldr r9, [r4, #8] @capacity

  sub r9, r8, r9 @subtract capacity
  sdiv r9, r9, r10 @divide capacity by 44 bits

  sub r9, r6, r9 @subtract count from entity movement
  mul r2, r9, r10 @used for memmove

  sub r6, r6, #1  @sub up 1 
  strh r6, [r4, #2] @ready to store
  mov r0, r8 @ the source

  add r1, r0, #44 @the destination
  bl memmove @copy bytes

final:
  mov r0, #1 @found then delete
  pop {r4, r5, r6, r7, r8, r9, r10, lr}
  bx lr

delete_end:
  mov r0, #0 @not found so nothing happens
  pop {r4, r5, r6, r7, r8, r9, r10, lr}
  bx lr



    .global insert
    .data
W:  .word 0

insert:
  push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
  mov r11, #44 @student size
  ldrh r6, [r0, #0] @capacity
  ldrh r7, [r0, #2] @count


  cmp r7, r6 @check capacity
  bge insert_end @end if empty

  mov r4, r0 @table
  mov r5, r1 @id search
  mov r6, r2 @move r2 to r6
  ldr r2, =W @assign bytes
  bl search @search

  mov r8, r0 @r8 search

  ldr r9, [r2] @load r4
  cmp r8, #1 @if found it exists
  beq insert_end @end

  ldr r10, [r4, #8] @load r4

  sub r10, r9, r10 @subtract capacity

  sdiv r10, r10, r11 @total bytes divided by size
  sub r10, r7, r10 @subtract count 

  mov r8, r3 @to keep arg

  mul r2, r10, r11 @44 byte copy
  mov r1, r9 @destination
  add r0, r1, r11 @source
  bl memmove

  add r7, r7, #1 @increment count
  strh r7, [r4, #2]

  mov r11, r5 @id number
  mov r10, #0 @set r10 to 0
  strh r11, [r9] @store id in student

  mov r11, #0 @ counter
  mov r4, #2 @offset

insert_loop:

  ldrb r10, [r6, r11] @r2 to r6
  strb r10, [r9, r4] @character to r9
  cmp r10, #0 @compare to 0
  bne proceed @continue

  ldr r4, [sp, #32] @take exam1
  ldr r5, [sp, #36] @take exam2
  ldr r7, [sp, #40] @take hw

  ldrh r8, [r0, #4] @ total
  strh r4, [r9, #+28] @ exam1
  strh r5, [r9, #+30] @exam 2
  strh r7, [r9, #+32] @ homework

  mov r11, #0 @set total to 0
  add r11, r11, r4 @add exam 1
  add r11, r11, r5 @add exam 2
  add r11, r11, r7 @add homework
  strh r11, [r9, #+42] @store in total

  fmsr s0, r11 @make total into float
  fsitos s1, s0 @from int to float

  fmsr s2, r8 @from total to float
  fsitos s3, s2 @int to float
  fdivs s4, s1, s3 @division 
  fsts s4, [r0, #+36] @percentage

  mov r0, #1 @if succesful
  pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
  bx lr

insert_end:
  mov r0, #0 @if not
  pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
  bx lr

proceed:
  add r11, r11, #1
  add r4, r4, #1
  b insert_loop
    
