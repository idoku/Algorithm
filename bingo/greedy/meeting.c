#include <stdio.h>

typedef struct meet
{
    int num;
    int beg;
    int end;    
} meet;


void greedy(meet m[],int n);
void selection_sort(meet v[], int n);
void swap(meet *a,meet *b);
void printa(meet v[],int n);

int main()
{       
    meet t[10] = {{1,3,6},{2,1,4},{3,5,7},{4,2,5},
    {5,5,9},{6,3,8},{7,8,11},{8,6,10},{9,8,12},{10,12,14}};    
    
    selection_sort(t,10);
    printa(t,10);
    greedy(t,10);
     
}

void greedy(meet m[],int n){
    int last = 0;    
    for (int i = 0; i < n; i++)
    {
         if(m[i].beg>last){            
             last = m[i].end;
             printf("m=%d ",m[i].num);
         }
    }
    
}

void selection_sort(meet v[], int n)
{
    int smallest;
    for (int i = 0; i < n; i++)
    {
        smallest = i;
        for (int j = i+1; j < n; j++)
        {
            if(v[j].end<v[smallest].end){
                smallest = j;
            }
        }
        swap(&v[i],&v[smallest]);
    }
    
}

void swap(meet *a,meet *b){
    meet t;
    t = *a;
    *a = *b;
    *b = t;
}


void printa(meet v[],int n){
    for (int i = 0; i < n; i++)
    printf("i=%d:beg=%d,end=%d\n", i,v[i].beg,v[i].end);
    printf("\n");
}