#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    long int tab[100000];
    long int i, j, tmp, n;
    
    printf("combien d'elements contient le tableau ?");
    scanf("%d",&n);
    printf("\nremplissez le tableau: ");
    for (i = 0; i < n; i++) scanf("%d",&tab[i]);

    for (i = 0; i < n; i++){
        j=i-1; 
        tmp=tab[i];
        while(j>=0 && tab[j]>tmp) {
            tab[j+1]=tab[j];
            j=j-1;
        }
        tab[j+1]=tmp;
    }

    printf("le tableau triee:");
    printf("[");
    for (i = 0; i < n; i++) printf("\t%d,",tab[i]);
    printf("]");

    return 0;    
}