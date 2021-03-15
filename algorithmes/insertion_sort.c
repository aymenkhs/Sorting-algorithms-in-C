#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort.h"

void insertionSort(long * table, long taille){
    /*
    cette fonction sert uniquement a appeller l'une des 2 fonctions (iterratif ou recurssive)
    dans le but de garder un "main" plus propre
    */
    tri_insertion_iteratif(table, taille);
}

void tri_insertion_iteratif(long * t, long n)
{

	long i,j,Temp;

	for(i=1;i<n;i++)
	{
		Temp = t[i];
		j=i-1;

		while(j>=0 && t[j]>Temp)
		{
			t[j+1] = t[j];
			j--;
		}

		t[j+1] = Temp;
	}

}


void tri_insertion_recursive(long *t,long i, long n)
{

	if(i<n)
	{
		long j,Temp;

		Temp = t[i];
		j=i-1;

		while(j>=0 && t[j]>Temp)
		{
			t[j+1] = t[j];
			j--;
		}

		t[j+1] = Temp;

		tri_insertion_recursive(t,i+1,n);
	}

}
