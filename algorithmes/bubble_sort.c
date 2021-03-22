#include <stdio.h>
#include <stdlib.h>

#include "bubble_sort.h"

void bubbleSort(long * table, long taille){
	int i,j;
	float x;
	for(i=taille;i>2;i--){
		for(j=0;j<i-1;j++){
			if(table[j] > table[j+1] ){
				x = table[j];
				table[j] = table[j+1] ;
				table[j+1] = x ;
			}
		}		
	}  
}
