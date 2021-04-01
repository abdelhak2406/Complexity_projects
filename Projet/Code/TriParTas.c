
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Length 50000
typedef long *array;
array A;
array Tmp;//reorganiser le tas en respectant les conraintes 
void heapify(array a, long i, long heapsize)
{
  long l, r, largest, tmp;
  l = 2*i;
  r = 2*i + 1;
  if(l <= heapsize && a[l] > a[i]){
    largest = l;
  }
  else{
    largest = i;
  }
  if( r <= heapsize && a[r] > a[largest]){
    largest = r;
  }
  if(largest != i){
    tmp = a[i];
    a[i] = a[largest];
    a[largest] = tmp;
    heapify(a, largest, heapsize);
  }
}//construire tas
void buildHeap(array a, long length){
  long i, heapsize;
  heapsize = length - 1;
  for( i=(length/2); i >= 0; i--)
  {
    heapify(a, i, heapsize);
  }
}
//tri par tas
void heapSort(array a, long length)
{
  buildHeap(a, length);
  long heapsize, i, tmp;
  heapsize = length - 1;
  for( i=heapsize; i >= 0; i--)
  {
    tmp = a[0];
    a[0] = a[heapsize];
    a[heapsize] = tmp;
    heapsize--;
    heapify(a, 0, heapsize);
  }
}
//main
int main()
{
    clock_t start, end;
    double time;
    long i;
    /*Allocation*/
    A =(long *)malloc(Length*sizeof(long));
    Tmp =(long *)malloc(Length*sizeof(long));
    /*Initialisation1 
    for(i=0;i<Length;i++){
         A[i]=Length-i;
    }*/
    /*Initialisation2 */
     for(i=0;i<Length;i++){
        A[i]=i;
    }
    /*Initialisation3
     for(i=0;i<Length;i++){
        A[i]=rand();
    }*/
    /*Affichage*/
    for(i=0;i<Length;i++){
        printf("%d ",A[i]);
    }
    start=clock();
    heapSort(A,Length);
    end=clock();
    time=(float)(end-start)/CLOCKS_PER_SEC; 
       /*Affichage tableau trié*/
    printf("\n\n");
    for(i=0;i<Length;i++){
        printf("%d ",A[i]);}
    printf("\n\nRuntime =  %f\n", time); //Display runtime}