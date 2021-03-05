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

    long * tab = generer_bon_ordre(10);
    for(int i=0; i<10; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");

    tab = generer_ordre_inverse(10);
    for(int i=0; i<10; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");

    tab = generer_random(10);
    for(int i=0; i<10; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
