#include <stdio.h>
#include <stdlib.h>

#include "tri_insertion.h"

void Tri_fusion(long * tab, int n)
{ int min,boolean,z;
	for(int i=0;i<n-1;i++)
  { min=i; boolean=0;
  	for(int j=i+1;j<n;j++)
  	 {
  	 	if(tab[min]>tab[j])
  	 	 {
  	 	 	min=j;
  	 	 	boolean=1;
		 }
	   }
	   if(boolean==1)
	    {
	      z=tab[i];
		  tab[i]=tab[min];
		  tab[min]=z;	
		}
  }
}
