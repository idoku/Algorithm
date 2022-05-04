#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(int v[],int n);
int *intdup(int const *src, size_t len);
void printa(int v[], int n);

int main()
{
     int arr[] = {2, 4, 6};
     // int *p = malloc((2) * sizeof(int));    
     
      //int *p = intdup(arr,0);
      //printf("%d",p==NULL);
    //  int *p = malloc((0) * sizeof(int));
    //  memcpy(p, arr, (0) * sizeof(int));
    //  int *p = intdup(arr,0);
    //  printf("%d",p[0]);
    // printa(p,3);

    //int size = sizeof arr / sizeof *arr;
    //printf("%d", size);
    //int *p = intdup(arr,size-1) ;
    //size = sizeof p / sizeof *p;
    //printf("%d", size);
    int res = count(arr,3);
    printf("%d", res);
}

int count(int v[],int n)
{            
    if (v == NULL)
        return 0;
    else
    {                                
        int *p = intdup(v,n-1); 
        return 1 + count(p,n-1);        
    }
}

int *intdup(int const *src, size_t len)
{     
    if(len==0){
       
        int *p = NULL;      
        return p;
    }
    int *p = malloc((len) * sizeof(int));    
    memcpy(p, src, (len) * sizeof(int));
    return p;
}

void printa(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", v[i]);
    printf("\n");
}