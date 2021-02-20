#ifndef base
#define base

// time measurement functions
double * tab_execution(int * (* function)(long), long * tab1);
double execution_time(int * (* function)(long), long n);

// tables generation
long * generer_bon_ordre(long n);
long * generer_ordre_dinverse(long n);
long * generer_random(long n);

// ecrire les resultats dans un fichier csv
writeCSV(int * tab1, double * results_part1, double * results_part2, double * results_part3)

#endif // base
