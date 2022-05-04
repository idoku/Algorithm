#include <stdio.h>

void quick_sort(int v[], int left,int right);
int partition(int v[],int p,int r);
void printa(int v[],int n);
void swap(int *a,int *b);

int main(int argc, char const *argv[])
{
	int arr[] = {9, 7, 5,3,1};
    printa(arr,5);
    quick_sort(arr,0,5);
    printa(arr,5);
	return 0;
}

void quick_sort(int v[], int left,int right)
{
    int q;
	if(left>=right) /* do nothing if array contains */
		return;	 
     q = partition(v,left,right-1);
     quick_sort(v,left,q-1);
     quick_sort(v,q+1,right-1);     
}

int partition(int v[],int p,int r){
     int q = p;
     for (int u = p; u < r; u++)
     {
         if (v[u]<=v[r])
         {            
            swap(&v[q],&v[u]);
            q++;
         }         
     }
     swap(&v[q],&v[r]);              
     return q;
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