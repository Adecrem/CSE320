//Project 7
//Andrew Decrem
#include <stdio.h>
#include "/user/cse320/Projects/project07.hardware.h"

void execute()
{
  signal4 rs2 = IR & 0xF;

  signal4 immediate = IR & 0xFF;

  signal4 rd = (IR >> 12) & 0xF;

  signal4 rs1 = (IR >> 16) & 0xF;

  signal4 s = (IR >> 20) & 0x1;

  signal4 opcode = (IR >> 21) & 0xF;
  
  signal4 i = (IR >> 25) & 0x1;

  signal4 c = CPSR >> 29 & 0x1;

  signal4 var = (IR >> 26) & 0x3f;

  signal4 operand2, result, RS1, RS2;

  signal4 is_i_1 = (IR >> 8) & 0xF;

  signal4 is_i_0 = (IR >> 4) & 0xFF;

  read_reg_file(rs1, rs2, &RS1, &RS2);

  if (i != 0x0){
    operand2 = immediate;
    if ((var != 0x38) || (is_i_1 != 0x0000)){
      CPSR = CPSR | 0x1;
      return;
   }
  }else{
    operand2 = RS2;
    if ((var != 0x38) || (is_i_0 != 0x00000000)){
      CPSR = CPSR | 0x1;
      return;
    }
  }

  if(opcode == 0x0){
    result = RS1 & operand2;

    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }else{
      CPSR = CPSR & 0x4FFFFFFE;
    }
    if (result == 0){
      CPSR = CPSR | 0x4;
    }


  }else if (opcode == 0x1){
    result = RS1 ^ operand2;
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
      
    }else{
      CPSR = CPSR & 0x4FFFFFFE;
    }
    if (result == 0){
      CPSR = CPSR | 0x4;
    }
  }
  else if(opcode == 0x2){
    result = RS1 - operand2;
    if (result >> 31 == 1)
    {
      CPSR = CPSR | 0x8;
    }
    if (result == 0)
    {
      CPSR = CPSR | 0x4;
    }
    if ((!RS1 >> 31 & operand2 >> 31) | ((result >> 31) & (!RS1 >> 31 | operand2 >> 31)))
    {
      CPSR = CPSR | 0x2;   
    }else{
      CPSR = CPSR & 0xDFFFFFFE;
    }
    if ((RS1 >> 31 != operand2 >> 31) & ((result >> 31) == operand2 >> 31))
    {
      CPSR = CPSR | 0x1;
    }

  }
  else if (opcode == 0x3){
    result = operand2 - RS1;
    if (result >> 31 == 1){
    
      CPSR = CPSR | 0x8;
    }
    if (result = 0)
    {
      CPSR = CPSR | 0x4;
    }
    if ((!RS1 >> 31 & operand2 >> 31) | ((result >> 31) & (!RS1 >> 31 | operand2 >> 31)))
{
  CPSR = CPSR | 0x2;
}
    if ((RS1 >> 31 != operand2 >> 31) & ((result >> 31) == operand2 >> 31))
{
  CPSR = CPSR | 0x1;
}
  }else if (opcode == 0x4){
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }else{
      CPSR = CPSR & 0x7FFFFFFE;
    }
    if (result == 0){
      CPSR = 0x4;
    }if ((!RS1 >> 31 & operand2 >> 31) | ((result >> 31) & (!RS1 >> 31 | operand2 >> 31)))
    {
      CPSR = CPSR | 0x2;
    }else{
      CPSR = CPSR & 0xDFFFFFFE;
    }
    if ((RS1 >> 31 != operand2 >> 31) & ((result >> 31) == operand2 >> 31))
    {
      CPSR = CPSR | 0x1;
    }
  }



  else if (opcode == 0x5){
    result = RS1 + operand2 + c;
    if (result >> 31 == 1)
    {
      CPSR = CPSR | 0x8;
    }else{
      CPSR = CPSR & 0x7FFFFFFE;
    }
    if (result == 0){
      CPSR = CPSR | 0x4;
    }
    if ((RS1 >> 31 & operand2 >> 31) | (!(result >> 31) & (RS1 >> 31 | operand2 >> 31)))
    {
      CPSR = CPSR | 0x2;
    }else{
      CPSR = CPSR & 0xDFFFFFFE;
    }
    if ((RS1 << 31 == operand2 << 31) & ((result >> 31) != RS1 >> 31))
    {
      CPSR = CPSR | 0x1;
    }
  } 
  else if(opcode == 0x6){
    result = RS1 - operand2 - (~c);
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }else{
      CPSR = CPSR & 0x7FFFFFFE;
    }
    if (result == 0)
    {
      CPSR = CPSR | 0x4;
    }
    if ((!RS1 << 31 & operand2 << 31) | ((result >> 31) & (!RS1 >> 31 | operand2 >> 31)))
    {
      CPSR = CPSR | 0x2;
    }else{
      CPSR = CPSR & 0xDFFFFFFE;
    }
    if ((RS1 >> 31 != operand2 >> 31) & ((result >> 31) == operand2 >> 31))
    {
      CPSR = CPSR | 0x1;
    }
  }

  else if(opcode == 0x7){
    result = operand2 - RS1 - (~c);
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }else{
      CPSR = CPSR & 0x7FFFFFFE;
    }
    if (result == 0){
      CPSR = CPSR | 0x4;
    }
    if ((!RS1 >> 31 & operand2 >> 31) | ((result >> 31) &(!RS1 >> 31 | operand2 >> 31)))
    {
      CPSR = CPSR | 0x2;
    }else{
      CPSR = CPSR & 0xDFFFFFFE;
    }
    if ((operand2 >> 31 != RS1 >> 31) & ((result >> 31) == RS1 >> 31))
    {
      CPSR = CPSR | 0x1;
    }
  }else if (opcode == 0x8){
    if (s != 0x1){
      return;
    }
    result = RS1 & operand2;
    if (result >> 31 == 1)
    {
      CPSR = CPSR | 0x8;
    }else{
      CPSR = CPSR & 0x4FFFFFFE;
    }
    if (result == 0)
    {
      CPSR = CPSR | 0x4;
    }
  }else if (opcode == 0x9){
    if (s != 0x1){
      return;
    }
    result = RS1 ^ operand2;
    if (result >> 31 == 1)
    {
      CPSR = CPSR | 0x8;
    }else{
     CPSR = CPSR &  0x4FFFFFFE;
    }
    if (result == 0)
    {
      CPSR = CPSR | 0x4;
    }
  }else if (opcode == 0xA){
    result = RS1 ^ operand2;
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }else{
      CPSR = CPSR & 0x7FFFFFFE;
    }
    if (result == 0)
    {
      CPSR = CPSR | 0x4;
    }

  }else if (opcode == 0xB){
    if (s != 0x1){
      return;
    }
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }
    if (result == 0)
    {
      CPSR = CPSR | 0x4;
    }
  }else if (opcode == 0xC){
    result = RS1 | operand2;
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }
    if (result == 0)
    {
      CPSR = CPSR | 0x4;
    }
  }else if (opcode == 0xD){
    result = operand2;
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }
    if (result == 0){
      CPSR = CPSR | 0x4;
    }
  }else if (opcode == 0xE){
    result = RS1 & ~operand2;
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    } 
    if (result == 0){
      CPSR = CPSR | 0x4;
    }
  }else if (opcode == 0xF){
    result = ~operand2;
    if (result >> 31 == 1){
      CPSR = CPSR | 0x8;
    }
    if (result == 0){
      CPSR = CPSR | 0x4;
    }
  }

  
  write_reg_file(rd, result);

}
