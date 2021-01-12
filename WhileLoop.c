#include<stdio.h>
#include <stdlib.h> 
int main()
{
   double i=1,n,s=0;
   printf("give a number: \n");
   scanf("%lf",&n); 
   while(i<=n) {s=s+i; i++;}
   printf("la somme des nombres de 1 jusquau nombre donné est: %lf",s);
   return (0);
}