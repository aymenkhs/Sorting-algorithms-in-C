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

    char function_names[2][20] = { "Heap sort", "Quick sort" };

    int (* fonctions [2])(long*, long) = {heapSort, quickSort};

    long tab[6] = {10, 100};

    

    


    for (int i = 0; i < 2; i++) {

        printf("%s started.\n", function_names[i]);

        StoreTime* results = tab_execution(fonctions[i], tab, 2);

        writeCSV(function_names[i], results, 2);

        printf("%s done.\n\n", function_names[i]);

    }

    

    

    return EXIT_SUCCESS;
}
