
#include <stdio.h>

int gcd(int m,int n);

 
int main(int argc, char const *argv[])
{
    int r = gcd(528,129);
    printf("%d",r);
}


int gcd(int m,int n)
{
    if(n==0){
        return m;
    }
    
    return gcd(n,m%n);
}

 
 