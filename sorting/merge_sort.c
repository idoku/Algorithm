#include <stdio.h>
#include <limits.h>

void merge_sort(int v[], int p, int r);
void merge(int v[], int p, int q, int r);
void printa(int v[], int n);
void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
   int arr[] = {9, 7, 5,3,1};
    int n=5;       
    printa(arr, n);
    merge_sort(arr, 0,n-1);
    printa(arr, n);
    return 0;
}

void merge_sort(int v[], int p, int r)
{  
    //printf("-%d-%d-\n",p,r); 
    int q;
    if (p >= r) /* do nothing if array contains */
        return;
   q = (p + r) / 2;   
   merge_sort(v, p, q);
   merge_sort(v, q + 1, r);
   merge(v, p, q, r);
}

void merge(int v[], int p, int q, int r)
{    
    int n1 = q - p+1;
    int n2 = r - q;
    int b[n1], c[n2];    
    for (int i = 0; i < n1; i++)
    {
        b[i] = v[p+i];
    }    
    for (int j = 0; j < n2; j++)
    {
        c[j] = v[q+1+j];
    }
     b[n1] = INT_MAX;     
     c[n2] = INT_MAX;    
     //printa(b,n1+1);
     //printa(c,n2+1);
    int i = 0,j=0;    
    for (int k = p; k < r+1; k++)
    {
        if (b[i] <= c[j])
        {
            v[k] = b[i++];            
        }
        else
        {
            v[k] = c[j++];           
        }
    }
    //printa(v,r);
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void printa(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}