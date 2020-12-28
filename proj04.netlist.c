/******************************************************************************
 * Author: Andrew Decrem
  Project #4 skeleton
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;
  
  Pulser ((SD("2a"), "I --------- Init "), Init, 'i', 10000);
  Pulser ((SD("3a"), "C --------- Clock "), Clock, 'c', 10000);

  // Replace with code for your Pulsers

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  // Replace with code for your Probes
  Probe ((SD("1e"),"w()"), w);
  Probe ((SD("2e"),"x()"), x);
  Probe ((SD("3e"),"y()"), y);
  Probe ((SD("4e"),"z()"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );
  
  // Replace with declarations for any auxiliary Signals
  Signal notw, notx, noty, notz, and1, and2, and3, and4, and5, and6,and7, and8, W, X, Y, Z;
  // Replace with code for your DFFs
  Dff (SD(sd, "1d"), (Init, W, Clock, Zero), w);
  Dff (SD(sd, "2d"), (Zero, X, Clock, Init), x);
  Dff (SD(sd, "3d"), (Init, Y, Clock, Zero), y);
  Dff (SD(sd, "4d"), (Zero, Z, Clock, Init), z);
  // Replace with circuit implementation (Not, And, Or gates)
  Not (SD(sd, "1g"), w, notw);
  Not (SD(sd, "2g"), x, notx);
  Not (SD(sd, "3g"), y, noty);
  Not (SD(sd, "4g"), z, notz);

  //W()
  And (SD(sd, "1c"), (z, notx), and1);
  And (SD(sd, "2c"), (y, notw), and2);
  Or  (SD(sd, "1e"), (and1, and2), W);

  //X()
  And (SD(sd, "3c"), (notz, w), and3);
  And (SD(sd, "4c"), (noty, z, notw), and4);
  Or (SD(sd, "2e"), (and3, and4), X);

  //Y()
  And (SD(sd, "5c"), (noty, notw), and5);
  And (SD(sd, "6c"), (noty, z), and6);
  Or (SD(sd, "3e"), (and5, and6), Y);

  //Z()
  And (SD(sd, "7c"), (y, notz), and7);
  And (SD(sd, "8c"), (noty, z, notw), and8);
  Or (SD(sd, "4e"), (and7, and8), Z);
}
