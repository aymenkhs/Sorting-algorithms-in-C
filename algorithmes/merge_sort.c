#include <stdio.h>
#include <stdlib.h>

#include "merge_sort.h"

void mergeSort(long * table, long taille){
    /*
    cette fonction sert uniquement a appeller la fonction Tri_fusion avec es paramettres
    table, 0 et taille
    dans le but de garder un "main" plus propre
    */
    Tri_fusion(table, 0, taille);
}

void Fusion(long * tab, long debut, long m, long fin)
    {
        long *T2 = NULL;
        long i, j, k;

        T2 = malloc((fin-debut+1) * sizeof(long));
        i = debut;
        j = m+1;
        k = 0;
        while (i <= m && j <= fin)
        { if (tab[i] <= tab[j])
            { T2[k] = tab[i];
              i++;}
          else{
                T2[k] = tab[j];
                j++;
              }
          k++;
        }
        // Copiez tous les éléments restants du tableau non vide
        while (i <= m)
        {
            T2[k] = tab[i];
			      i++;
            k++;
        }

        while (j <= fin)
        {
            T2[k] = tab[j];
            j++;
            k++;
        }
        k=0;
        for(int i=debut; i<=fin; i++)
           {
            tab[i]=T2[k];
            k++;
           }
        free(T2);
    }

void Tri_fusion(long * T, long debut ,long fin)
{
  long m;
  if(debut < fin)
   {
     m=(debut+fin)/2;
     Tri_fusion(T,debut,m);
	   Tri_fusion(T,(m+1),fin);
   	 Fusion(T,debut,m,fin);
   }
 }
