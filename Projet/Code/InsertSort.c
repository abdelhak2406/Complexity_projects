#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    long int tab[1000000];
    long int i, j, tmp;
    long int n[]={50000, 100000, 200000, 400000, 800000};
    clock_t t1,t2;
    
    int q=0;
    while (q<7){
    for (i = 0; i < n[q]; i++) tab[i]=rand();
    t1=clock();
    for (i = 0; i < n[q]; i++){
        j=i-1; tmp=tab[i];
        while(j>=0 && tab[j]>tmp) {
            tab[j+1]=tab[j];
            j=j-1;
        }
        tab[j+1]=tmp;
    }
    t2=clock();
    printf("\nle temps d'exec est: %f",(double)(t2-t1)/CLOCKS_PER_SEC);
    q++;
    }
    return 0;    
}