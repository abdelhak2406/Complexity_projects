#include<stdio.h>
#include <stdlib.h> 
int main()
{
   double i=0,n,s=0;
   printf("give a number: \n");
   scanf("%lf",&n); 
   for(i=1;i<=n;i++) {s=s+i;}
   printf("la somme des nombres de 1 jusquau nombre donné est: %lf",s);
   return (0);
}