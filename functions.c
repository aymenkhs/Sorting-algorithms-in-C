#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "functions.h"


//  Fonction  qui  prend en parametre une fonction est un tebleau d'entier n et qui retourne le temps d'execution de chaque n dans un autre tableau
StoreTime * tab_execution(int * (* function)(long*, long), long * tab, int taille){

    long *ordered_tab, *inverse_tab, *random_tab;
    StoreTime *results = malloc(taille * sizeof(StoreTime));

    for(int i=0; i<taille; i++){
        results[i].num = tab[i];

        ordered_tab = generer_bon_ordre(tab[i]);
        results[i].time_ordered = execution_time(function, ordered_tab, taille);

        inverse_tab = generer_ordre_inverse(tab[i]);
        results[i].time_inverse = execution_time(function, inverse_tab, taille);

        random_tab = generer_random(tab[i]);
        results[i].time_random = execution_time(function, random_tab, taille);

        free(ordered_tab);
        free(inverse_tab);
        free(random_tab);
    }
    return results;
}

//  Fonction  qui  retourne  le  temps d’execution de la fonction donner en parametre
double execution_time(int * (* function)(long*, long), long * tab, long n){
    clock_t t1 , t2;

    t1 = clock ();
    function(tab, n);
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
        random_number = rand() % n;
        tab[i] = random_number;
    }
    return tab;
}

// fonction qui ecris dans un fichier csv les resultats des mesures de temps
int writeCSV(char * algorithm ,StoreTime * results, int taille){

    FILE* fp = NULL;
    char * file_name = malloc((15 + strlen(algorithm)) * sizeof(char));

    sprintf(file_name, "results/%s.csv", algorithm);
    fp=fopen(file_name,"w+");

    if (fp == NULL){
        printf("wellll");
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
