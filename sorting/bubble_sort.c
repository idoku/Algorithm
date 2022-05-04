#include <stdio.h>

void bubble_sort(int v[], int n);
void printa(int v[],int n);
void swap(int *a,int *b);

int main(int argc, char const *argv[])
{
	int arr[] = {9, 7, 5, 3, 1};
    printa(arr,5);
    bubble_sort(arr,5);
    printa(arr,5);
	return 0;
}

void bubble_sort(int v[], int n)
{    
    for (int i = 0; i < n-1; i++)
    {       
        for (int j = 0; j < n-1; j++)
        {
            if(v[j]>v[j+1]){
                swap(&v[j],&v[j+1]);
            }
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