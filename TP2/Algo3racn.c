#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
/*pour resoudre la possible erreurs d'execution ajouter -lm
    gcc Algo3racn.c -o alg3 -lm
*/
int main(int argc, char const *argv[])
{   
    long int n,i=2,racine,premier=1;//0 == faux ; 1==vrai
    double delta;
    clock_t t1, t2 ;

    printf("introduire la valeur de  n\n");
    scanf("%li",&n);
    t1 = clock();
    racine =  (long int)sqrt(n);
    while ((i< racine) && (premier))
    {
        if( n % i == 0 ) {  
            premier = 0;
        }else
        {
            i++;
        }
    }

    
    if (premier)
    {
        printf("%li est un nombre premier\n",n);
    }else  
    {
        printf("%li n'est pas un nombre premier\n",n);
    }
    t2 = clock();
    delta = (double) (t2-t1)/CLOCKS_PER_SEC ;
    printf("time excution is: %lf seconds \n",delta);
    
}
