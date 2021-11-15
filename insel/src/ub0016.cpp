/*-----------------------------------------------------------------------
  #Begin
  #Block UBQUADRATICEQ
  #Description
     
  #Layout
     #Inputs     1
     #Outputs    3
     #Parameters 2
     #Strings    0
     #Group      S
  #Details
     #Inputs
        #IN[0] independent term
     #Outputs
        #OUT[0] solution for positive root
        #OUT[1] solution for negative root
        #OUT[2] warnings
     #Parameters
        #BP[0] a constant 
        #BP[1] b constant
     #Strings
        #None
  #Internals
     #Integers
        #IP[0]  Return code
        #IP[1]  Call mode
                \begin{detaillist}
                   \item[-1] Identification call
                   \item[0]  Standard call
                   \item[1]  Constructor call
                   \item[2]  Destructor call
                \end{detaillist}
        #IP[2]  Operation mode
        #IP[3]  User defined block number
        #IP[4]  Number of current block inputs
        #IP[5]  Jump parameter
        #IP[6]  Debug level
        #IP[7..9]  Reserved
     #Reals
        #None
     #Doubles
        #None
  #Dependencies
     #None
  #Authors
     INSEL Block Wizard
  #End
-----------------------------------------------------------------------*/

// Attention: out must not be renamed to OUT (Windows.h conflict)
#include <iostream>
#include <cmath>

extern "C" void id (float *in, float *out, int *IP, float *RP, double *DP,
                    float *BP, char SP[][1024], char BNAMES[1024],
                    int *OPM, int *INMIN, int *INS, int *OUTS,
                    int *IPS, int *RPS, int *DPS,
                    int *BPMIN, int *BPS, int *SPMIN,
                    int *SPS, int *GROUP);

extern "C" void ub0016(float *in, float *out, int *IP, float *RP,
   double *DP, float *BP, char SP[][1024])
{
   char BNAMES[1024] = "UBQUADRATICEQ";
   int  OPM   = 1;
   int  INMIN = 1;
   int  INS   = 1;
   int  OUTS  = 3;
   int  IPS   = 10;
   int  RPS   = 0;
   int  DPS   = 0;
   int  BPMIN = 2;
   int  BPS   = 2;
   int  SPMIN = 0;
   int  SPS   = 0;
   int  GROUP = 3;
   float aa, bb, cc, xplus, xminus, delta;
   int warning;


   if (IP[1] != 0)
   {
      if (IP[1] == -1)
      {
          // Identification call
          id(in, out, IP, RP, DP, BP, SP, BNAMES,
             &OPM, &INMIN, &INS, &OUTS, &IPS, &RPS, &DPS,
             &BPMIN, &BPS, &SPMIN, &SPS, &GROUP);
      }
      else if(IP[1] == 1)
      {
         // Constructor call
      }
      else
      {
         // Destructor call
      }
      return;
   }
   // Standard call ----------------------------------------------------
   cc = in[0];
   aa = BP[0];
   bb = BP[1];

   delta = bb*bb - 4*aa*cc;

   if (delta > 0){
   	xplus = ((-1)*bb+sqrt(delta))/(2*aa);
   	xminus = ((-1)*bb-sqrt(delta))/(2*aa);
        warning = -1;
   }else if (delta == 0){
     xplus = (-1)*bb/(2*aa);
     xminus = xplus;
     warning = -1;
   }else {
        xplus = -1;
        xminus = -1;
        warning = 1;
   }
   out[0] = xplus;
   out[1] = xminus;
   out[2] = warning;
   std::cout << out[0] << "\n";
   
}
