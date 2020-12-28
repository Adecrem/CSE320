
/******************************************************************************
  Andrew Decrem
  Project #3 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;
  Signal Strobe (1);
  Signal ResetA (1);
  Signal ResetB (1);

  Pulser ((SD("1a"), "r -- Reset counter"), ResetA, 'r', 10000);
  Pulser ((SD("2a"), "s -- Strobe counter"), Strobe, 's', 10000);

  Not (SD("1b"), ResetA, ResetB);

  // Replace with code to generate four input signals

  Counter((SD("1c-2c"), "4-bit counter"), (ResetB, Strobe), (w, x, y, z));

  circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);
//CODE ABOVE FROM LAB03
  // Replace with code to display eight output signals
  Probe ((SD("1f"), "present"), Present);
  Probe ((SD("2f"), "a"),a);
  Probe ((SD("3f"), "b"),b);
  Probe ((SD("4f"), "c"),c);
  Probe ((SD("5f"), "d"),d);
  Probe ((SD("6f"), "e"),e);
  Probe ((SD("7f"), "f"),f);
  Probe ((SD("8f"), "g"),g);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  // Replace with declarations for any auxiliary Signals
   Signal notw, notx, noty, notz;
   Signal and1, and2, and3, and4, and5, and6, and7;
  // Replace with circuit implementation (Not, And, Or gates)
  Not (SD(sd, "1a"), w, notw);
  Not (SD(sd, "2a"), x, notx);
  Not (SD(sd, "3a"), y, noty);
  Not (SD(sd, "4a"), z, notz);
 //present 
  And (SD(sd, "2d"), (notw, noty, z), and1);
  And (SD(sd, "3d"), (notw, y, notz), and2);
  And (SD(sd, "4d"), (x, noty, z), and3);
  And (SD(sd, "5d"), (w, notx, notz), and4);

  Or (SD(sd, "1f"), (and1, and2, and3, and4), Present);

 //a()
  Or (SD(sd, "2f"), (notz, x), a);

 //b()
  Or (SD(sd, "3f"), (notx, notz, w), b);
 //c()
  Or (SD(sd, "4f"), (z, y), c);
 //d()
  And (SD(sd, "2b"), (notw, notz), and5);
  And (SD(sd, "3b"), (noty, notz), and6);
  And (SD(sd, "4b"), (notw, x), and7);

  Or (SD(sd, "5f"), (and5, and6, and7), d);

 //e()
  Or (SD(sd, "6f"), (notx, notz), e);
 //f()
 
  Or (SD(sd, "7f"), (notw, y), f);

 //g()
  
  Or (SD(sd, "8f"), (notw, notx), g);

}

