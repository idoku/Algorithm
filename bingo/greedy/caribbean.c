#include <stdio.h>

void bubble_sort(int v[], int n);
void swap(int *a,int *b);
int greedy(int v[],int n,int weight);
void printa(int v[],int n);

int main()
{
    int v[] = {4,10,7,11,3,5,14,2};
    bubble_sort(v,8);
    printa(v,8);
    int res = greedy(v,8,30);
    printf("%d ",res);
}

int greedy(int v[],int n,int weight){
    int tmp = 0,total=0;
    for (int i = 0; i < n; i++)
    {        
        tmp+=v[i];
        if(tmp<weight){
            total = tmp;
        }else{
            break;
        }
    }
    return total;
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
    printf("%d ", v[i]);
    printf("\n");
}