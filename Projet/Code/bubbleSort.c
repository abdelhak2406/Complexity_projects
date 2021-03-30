#include <stdio.h>
#include <stdlib.h>
#include<time.h>    
#include<math.h>   
#define LENGTH 10
int tabTrie[LENGTH],tabTrieInverse[LENGTH],tabNonTrie[LENGTH];
double tempsExec;
clock_t t1,t2;

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
  
       // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
  
/* Afficher tableau!!*/

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void createSorted(int arr[], int length){
    for (int i =0; i < length; i++)
    {
        arr[i] =i;

    }
    
}

void createReverseSorted(int arr[], int length){
    int i,j;
    for ( i = length-1, j=0 ; j < length; i-- , j++)
    {
        arr[j] = i;
    }
}

void createRandom(int arr[], int length){
    int i,j;
    for ( i = 0 ; i < length; i++  )
    {
        arr[i] = rand();
    }
}

void createArrays(int len ,int arrSort[], int arrInvSort[],int arrRan[]){
    //TODO: supprimer car normallement useless! 
    /*
        Procedure qui creer les 3 types de tableaux
            a- Deja trie
            b- trie inverse
            c- Non trie
    */    
    
    createSorted(arrSort,len);
    
    //printArray(tabTrie,LENGTH);    
   
    createReverseSorted(arrInvSort,len);
    //printArray(tabTrieInverse,LENGTH);
    createRandom(arrRan,len);
}

int main()
{
    //TODO: s'arreter  a (4*10)**5
    int len;
    int tabTaille[4] = {5*pow(10,4), pow(10,5), 2*pow(10,5), 4*pow(10,5)    }; 

    //!Code tableau trie dans bon ordre


        FILE *fptr;//enregistrer les resultats dans un fichier csv
        fptr = fopen("results_ordonne_a.csv","w");

        
        if (fptr== NULL){
            printf("ERROR");
            exit(1);
        }
        fprintf(fptr,"n(s),T");
        
        for (size_t i = 0; i < 4; i++)
        {  
            
            int tabi[tabTaille[i]];
            createSorted(tabi,tabTaille[i]);

            t1 =  clock();
            bubbleSort(tabi,tabTaille[i]);
            t2 = clock();
            tempsExec = (double) (t2-t1) / CLOCKS_PER_SEC ; 
            fprintf(fptr,"\n%d ,%lf",tabTaille[i],tempsExec) ;

            printf("Temps d\'execution: %lf s \n",tempsExec);
        }
        
        fclose(fptr);

        printf("\n\n\nFin du 1er tableau trie n\n\n");


    // ! Code tableau trie inverse
        printf("\n\n\nDemarrrage du 2eme trie avec tableau trie inverse  \n\n\n");
        fptr = fopen("results_ordonneInverse_b.csv","w");

        
        if (fptr== NULL){
            printf("ERROR");
            exit(1);
        }
        fprintf(fptr,"n(s),T");
        
        for (size_t i = 0; i < 4; i++)
        {  
            
            int tabi[tabTaille[i]];
            createReverseSorted(tabi,tabTaille[i]);

            t1 =  clock();
            bubbleSort(tabi,tabTaille[i]);
            t2 = clock();
            tempsExec = (double) (t2-t1) / CLOCKS_PER_SEC ; 
            fprintf(fptr,"\n%d ,%lf",tabTaille[i],tempsExec) ;

            printf("Temps d\'execution: %lf s \n",tempsExec);
        }

        fclose(fptr);
    // ! Code tableau non ordonne 

        printf("\n\n\nDemarrrage du 3eme trie avec tableau non trie n\n\n");
        fptr = fopen("results_ordonneRandom_c.csv","w");

        
        if (fptr== NULL){
            printf("ERROR");
            exit(1);
        }
        fprintf(fptr,"n(s),T");
        
        for (size_t i = 0; i < 4; i++)
        {  
            
            int tabi[tabTaille[i]];
            createRandom(tabi,tabTaille[i]);

            t1 =  clock();
            bubbleSort(tabi,tabTaille[i]);
            t2 = clock();
            tempsExec = (double) (t2-t1) / CLOCKS_PER_SEC ; 
            fprintf(fptr,"\n%d ,%lf",tabTaille[i],tempsExec) ;

            printf("Temps d\'execution: %lf s \n",tempsExec);
        }

        fclose(fptr);

    return 0;

}