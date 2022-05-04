#include <stdio.h>
#include <stdbool.h>
 
#define MAX(a,b) ((a)>(b)?(a):(b))


void comb_sort(int v[], int n);
void printa(int v[],int n);
void swap(int *a,int *b);

int main(int argc, char const *argv[])
{
	int arr[] = {9, 7, 5, 3, 1};
    printa(arr,5);
    comb_sort(arr,5);
  
    printa(arr,5);
	return 0;
}

void comb_sort(int v[], int n)
{    
    int j=n;
    double s=1.3;
 
    bool flag = false;
    while (j>1 || flag)
    {       
         int i = 0;
         j = MAX(j/s,1);      
         flag = false;
         while (i+j<n)
         {
             if(v[i]>v[i+j]){
                swap(&v[i],&v[i+j]);
                flag = true;
             }
             i = i+1;
         }         
    }    
}

void swap(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

 

void printa(int v[],int n){
    for (int i = 0; i < n; i++)
    printf("%d", v[i]);
    printf("\n");
}