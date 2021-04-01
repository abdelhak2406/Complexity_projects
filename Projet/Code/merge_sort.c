/* Programme en C pour le Tri fusion*/
#include <stdio.h>
#include <stdlib.h>

// fusionne deux sous tableaux de tableau T
// Le premier tableau est T[l..m]
// Sle second tableau est T[m+1..r]
void Fusionner(int T[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* creation de tableaux temporaires L (left) et R (right) */
	int L[n1], R[n2];

	/* remplir les tableaux R et L avec les valeurs du Tableau T (gauches pour L et droites pour R) */
	for (i = 0; i < n1; i++)
		L[i] = T[l + i];
	for (j = 0; j < n2; j++)
		R[j] = T[m + 1 + j];

	/* fusionner les deux tableaux temporaires en un seul Tableau T*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			T[k] = L[i];
			i++;
		}
		else {
			T[k] = R[j];
			j++;
		}
		k++;
	}

	/* copier d'autres elements dans L s'il en reste*/
	while (i < n1) {
		T[k] = L[i];
		i++;
		k++;
	}

	/* copier d'autres elements dans R s'il en reste */
	while (j < n2) {
		T[k] = R[j];
		j++;
		k++;
	}
}

/* l est l'index du tableau gauche et r est l'index du tableau droit */
void TriFusion(int T[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		// Trier les deux moitiés du tableau origine
		TriFusion(T, l, m);
		TriFusion(T, m + 1, r);

		Fusionner(T, l, m, r);
	}
}

/* Affichage du Tableau résultant */
void Afficher(int A[], int size)
{
	int i;
    printf("[");
	for (i = 0; i < size; i++)
    {
        if(i==(size-1)) 
        {printf("%d", A[i]);}
        else
		{printf("%d,", A[i]);}
    }
    printf("]");
}

/* Remplissage d'un tableau*/
void Remplir(int A[],int taille)
{
    int i;
    for(i=0;i<taille;i++)
    {
        printf("Donnez l'element %d:",i+1);
        scanf("%d",&A[i]);
        printf("\n");
    }
}

int main()
{
    //récuperer taille du tableau
    int taille;
    printf("donnez la taille de votre tableau:\n");
    scanf("%d",&taille);

    int A[taille];
    //Remplir le tableau
    Remplir(A,taille);

    //afficher tableau avant tri
    printf("\n LE TABLEAU AVANT TRI \n");
    Afficher(A,taille);

    //appliquer le tri fusion
    TriFusion(A, 0, taille - 1);

    //Afficher tableau après tri
	printf("\n LE TABLEAU APRES TRI \n");
	Afficher(A, taille);
	return 0;
}
