#include<stdio.h>
#include <stdlib.h> 
int main()
{
   double i=0,n,s=0;
   printf("give a number: \n");
   scanf("%lf",&n); 
   do {s=s+i; i++;}while (i<=n);
   printf("la somme des nombres de 1 jusquau nombre donné est: %lf",s);
   return (0);
}