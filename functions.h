#ifndef base
#define base

// structur to store the results of the time execution
typedef struct StoreTime StoreTime;
struct StoreTime
{
	long num; // the size of the table
    double time_ordered; // time to sort a list in good order
    double time_inverse; // time to sort a list in inverse order
    double time_random; // time to sort a random list
};

// time measurement functions
StoreTime * tab_execution(int * (* function)(long*, long), long * tab, int taille);
double execution_time(int * (* function)(long*, long), long * tab, long n);

// tables generation
long * generer_bon_ordre(long n);
long * generer_ordre_inverse(long n);
long * generer_random(long n);

// ecrire les resultats dans un fichier csv
int writeCSV(char * algorithm ,StoreTime * results, int taille);

#endif // base
