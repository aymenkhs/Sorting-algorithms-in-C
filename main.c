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

    char function_names[5][20] = {"Insertion Sort", "Bubble Sort", "Merge Sort", "Quick sort", "Heap sort"};

    int (* fonctions [5])(long*, long) = {insertionSort, bubbleSort, mergeSort, quickSort, heapSort};

    long *tab = NULL;
    long debut = 500, fin = 2048000;
    int taille;
    tab = generer_tailles_tableaux(debut, fin, &taille);

    for (int i = 0; i < 5; i++) {

        printf("%s started.\n", function_names[i]);

        StoreTime* results = tab_execution(fonctions[i], tab, taille);

        writeCSV(function_names[i], results, taille);

        printf("%s done.\n\n", function_names[i]);

    }

    return EXIT_SUCCESS;
}
