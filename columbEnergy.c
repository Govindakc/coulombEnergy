// _author_
// Govinda KC
// The University of Texas at El Paso.

// This program calculates the columb's energy
// The computed energy is compared to Delphi Software and results are consistent
// Energy is measured interms of kT where k is Boltzmann constant 1.38064852 SI unit and T is thermal temp (300 K) 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define e 1.60217662e-19
#define ang 1e-10 /* angstrom -> meter */
#define Epsilon 2*(8.85418782e-12) /* Epsilon_m = Epsilon_0 * Epsilon_r (=2), (delphi also used 2) */
#define Constant (1/(4*M_PI*Epsilon))
#define T_constant ((Constant*e*e)/1e-10) /* divided by 1e-10 because distance between atoms are in A0, 1A0 = 1e-10*/
#define ROW 38484
#define C 4.11e-21 /* C--> kT */
#define CC 280.99847 /* T_constant/C (divided by C) */
    
    int main()
    {	
	int i,j;
      	long double x[38484], y[38484], z[38484], q[38484], dx, dy, dz;
	long double R , E;
      	FILE *pqr=fopen("3ab.pqr", "r");
      	FILE *fout=fopen("results_ab.txt", "w");
      	for(i=0;(i<ROW) && (pqr != NULL); i++)
     	 {

	  fscanf (pqr,"%*s%*d%*s%*s%*s%*d%Lf%Lf%Lf%Lf%*Lf", &x[i], &y[i], &z[i], &q[i]);
	      }
        E = 0.0;
      
	for(i=0; i<ROW; i++)
     	    {
	for (j=0; j<ROW; j++)
	{
	  if(i<j){
 	  dx =(x[i] - x[j]);
          dy =(y[i] - y[j]);
          dz =(z[i] - z[j]);
          R = sqrt(dx*dx + dy*dy + dz*dz);
	  E= E+(q[i]*q[j]/R);
        	}
        }
            }
					
          fprintf(fout, "%.2Lf\n", (E*CC));
   return 0;
       }
