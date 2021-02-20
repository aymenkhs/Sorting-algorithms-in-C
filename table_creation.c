#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "table_creation.h"


//  Fonction  qui  prend en parametre une fonction est un tebleau d'entier n et qui retourne le temps d'execution de chaque n dans un autre tableau
double * tab_execution(int * (* function)(long), long * tab1){

    double *tab2 = malloc(12 * sizeof(double));

    for(int i=0; i<12; i++){
        tab2[i] = execution_time(function, tab1[i]);
    }

    return tab2;
}

//  Fonction  qui  retourne  le  temps d’execution de la fonction donner en parametre
double execution_time(int * (* function)(long), long n){
    clock_t t1 , t2;

    t1 = clock ();
    function(n);
    t2 = clock ();

    double temps_exe = (double) (t2 -t1)/CLOCKS_PER_SEC;
    return temps_exe;
}

// fonction qui genere un tableau d'entiers de taille n deja trier en ordre croissant
long * generer_bon_ordre(long n){

}


// fonction qui genere un tableau d'entiers de taille n trier en ordre inverse (decroissant)
long * generer_ordre_dinverse(long n){

}


// fonction qui genere un tableau d'entiers de taille n aleatoire
long * generer_random(long n){

}
