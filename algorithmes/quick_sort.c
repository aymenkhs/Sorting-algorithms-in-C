#include <stdio.h>
#include <stdlib.h>

#include "quick_sort.h"



// fonction qui permutte T[i] et T[j] 
void swap(long* table, int i, int j) {

	long temp;

	temp = table[i];
	table[i] = table[j];
	table[j] = temp;
}

// Fonction qui met les fonctions inf au pivot ensemble
long partition(long* table, long low, long high) {

	long i = low - 1, pivot = table[high], j;

	for (j = low; j < high; j++) {

		if (table[j] < pivot) {

			i++;
			swap(table, i, j);
		}
	}

	swap(table, i + 1, high);

	return i + 1;
}


//Fonction récursive
long* Sort(long* table, long low, long high) {

	if (low < high) {

		long pi = partition(table, low, high);

		Sort(table, low, pi - 1);
		Sort(table, pi + 1, high);

	}

	return table;
}




long* quickSort(long* table, long taille) {

	return Sort(table, 0, taille-1);
}
