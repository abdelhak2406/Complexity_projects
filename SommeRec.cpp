#include<time.h>
#include<stdio.h>
#include<stdlib.h>
double SommeRecursive(double n){
   if (n==1) return 1;
   else return (n+SommeRecursive(n-1));
}
int main()
{double n,somme=0,delta; 	clock_t t1, t2 ;
  
printf("give a number ");
scanf("%lf",&n);
      t1 = clock() ; 
      somme=SommeRecursive(n);
	  t2 = clock() ;
printf("voici la somme de 1 jusqu'au n donné %lf",somme);

   delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
   printf("time excution is %lf",delta);
    return 0;
}

