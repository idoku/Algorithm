#include <stdio.h>

typedef struct three
{
    int w;
    int v;
    double p;
} three;


double greedy(three t[],int n,int m);
void selection_sort(three v[], int n);
void swap(three *a,three *b);
void printa(three v[],int n);

int main()
{       
    three t[10] = {{4,3,0.75f},{2,8,4.0f},{9,18,2.0f},{5,6,1.2},
    {5,8,1.6},{8,20,2.5},{5,5,1},{4,6,1.5},{5,7,1.4},{5,15,3}};    
    
    selection_sort(t,10);
    //printa(t,10);
    double sum = greedy(t,10,30);
    printf("sum = %.2f",sum);
}

double greedy(three t[],int n,int m){
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        if(m>t[i].w){
             m-=t[i].w;             
             sum += t[i].v;             
        }
        else{            
            sum +=(double)m*t[i].p;  
            break;           
        }        
    }
    return sum;
}

void selection_sort(three v[], int n)
{
    int smallest;
    for (int i = 0; i < n; i++)
    {
        smallest = i;
        for (int j = i+1; j < n; j++)
        {
            if(v[j].p>v[smallest].p){
                smallest = j;
            }
        }
        swap(&v[i],&v[smallest]);
    }
    
}

void swap(three *a,three *b){
    three t;
    t = *a;
    *a = *b;
    *b = t;
}


void printa(three v[],int n){
    for (int i = 0; i < n; i++)
    printf("i=%d:w=%d,v=%d,p=%.2f\n", i,v[i].w,v[i].v,v[i].p);
    printf("\n");
}