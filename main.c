#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

#include "algorithmes/insertion_sort.h"
#include "algorithmes/bubble_sort.h"
#include "algorithmes/merge_sort.h"
#include "algorithmes/quick_sort.h"
#include "algorithmes/heap_sort.h"

int main(){
    srand(time(NULL));

    long *tab = NULL;
    long debut = 50000, fin = 204800000;
    int taille;

    int (* fonctions [5])(long*, long) = {insertionSort, bubbleSort, mergeSort, quickSort, heapSort};

    tab = generer_tailles_tableaux(debut, fin, &taille);

    StoreTime *results = tab_execution(fonctions[4], tab, taille);

    writeCSV("heapSort", results, taille);

    return EXIT_SUCCESS;
}
