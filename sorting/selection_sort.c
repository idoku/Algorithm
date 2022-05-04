#include <stdio.h>

void selection_sort(int v[], int n);
void printa(int v[],int n);
void swap(int *a,int *b);

int main(int argc, char const *argv[])
{
	int arr[] = {9, 7, 5, 3, 1};
    printa(arr,5);
    selection_sort(arr,5);
    printa(arr,5);
	return 0;
}

void selection_sort(int v[], int n)
{
    int smallest;
    for (int i = 0; i < n; i++)
    {
        smallest = i;
        for (int j = i+1; j < n; j++)
        {
            if(v[j]<v[smallest]){
                smallest = j;
            }
        }
        swap(&v[i],&v[smallest]);
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