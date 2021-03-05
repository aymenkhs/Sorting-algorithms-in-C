#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "functions.h"


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
    long *tab = malloc(n * sizeof(long));
    for(int i=0; i<n; i++){
        tab[i] = i+1;
    }
    return tab;
}


// fonction qui genere un tableau d'entiers de taille n trier en ordre inverse (decroissant)
long * generer_ordre_inverse(long n){
    long *tab = malloc(n * sizeof(long));
    for(int i=0; i<n; i++){
        tab[i] = n-i;
    }
    return tab;
}


// fonction qui genere un tableau d'entiers de taille n aleatoire
long * generer_random(long n){
    long random_number;
    long *tab = malloc(n * sizeof(long));
    for(int i=0; i<n; i++){
        random_number = rand() % 1000000;
        tab[i] = random_number;
    }
    return tab;
}

// fonction qui ecris dans un fichier csv les resultats des mesures de temps
int writeCSV(char * algorithm ,StoreTime * results, int taille){

    FILE* fp = NULL;
    char * file_name = strcat(algorithm, ".csv");
    fp=fopen(file_name,"w+");

    if (fp == NULL){
        return 0;
    }

    // this was a tp 2 part I'll change it to mach with our project
    fprintf(fp,"num,time_ordered,time_inverse,time_random");
    for(int i=0; i<taille; i++){
        fprintf(fp,"\n%d,%.10lf,%.10lf,%.10lf", results[i].num, results[i].time_ordered, results[i].time_inverse, results[i].time_random);
    }

    fclose(fp);

    return 1;
}
