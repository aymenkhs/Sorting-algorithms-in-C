#ifndef table_creation
#define table_creation

// time measurement functions
double * tab_execution(int * (* function)(long), long * tab1);
double execution_time(int * (* function)(long), long n);

// tables generation
long * generer_bon_ordre(long n);
long * generer_ordre_dinverse(long n);
long * generer_random(long n);

#endif // table_creation
