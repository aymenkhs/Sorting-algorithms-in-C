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

    int (* fonctions [1])(long*, long) = {heapSort};

    long tab[6] = {10, 100};

    StoreTime *results = tab_execution(fonctions[0], tab, 2);

    writeCSV("heapSort", results, 2);

    return EXIT_SUCCESS;
}
