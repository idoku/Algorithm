
#include <stdio.h>

int gcd(int m,int n);

void swap(int *a,int *b);

int main(int argc, char const *argv[])
{
    int r = gcd(528,129);
    printf("%d",r);
}


int gcd(int m,int n)
{
    if(n>m){
        swap(&m,&n);
    }
    
    while (n>0)
    {
       int r = m % n;
       m = n;
       n = r;
    }
    return m;
}

void swap(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

 