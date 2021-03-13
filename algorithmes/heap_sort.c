#include <stdio.h>
#include <stdlib.h>

#include "heap_sort.h"

long * heapSort(long * table, long taille){

    long x;

    heapCreation(table, taille);
    for(long i = taille-1; i>0; i--){
        x = table[i];
        table[i] = table[0];
        table[0] = x;
        entasser(table, i, 0);
    }
    return table;
}

long * heapCreation(long * table, long taille){
    for(long i = (long) (taille-1)/2; i>=0; i--){
        table = entasser(table, taille, i);
    }
    return table;
}

long * entasser(long * tab, long taille, long i){
    long imax = -1;
    long left_son = (2*i) + 1, right_son = (2*i) + 2;
    if(left_son < taille){ // in this case tab[i] isn't a leaf
        if(right_son < taille){ // we see if the tab[i] has a right child
            // in this case the the node have a right and left child
            if((tab[left_son] > tab[i]) || (tab[right_son] > tab[i])){
                if(tab[left_son] > tab[right_son]){
                    imax = left_son;
                } else {
                    imax = right_son;
                }
            }
        } else if (tab[left_son] > tab[i]) {
            // in this case the node only have a left child
            imax = left_son;
        }
    }
    /*
        if imax is different then -1 this mean that we need to make a permutation
        between i and imax, we need then to check the if the childs of the new
        permuted element still respect the rules of the heap.
    */
    if(imax != -1){
        long temp;
        temp = tab[i];
        tab[i] = tab[imax];
        tab[imax] = temp;
        tab = entasser(tab, taille, imax);
    }
    return tab;
}
