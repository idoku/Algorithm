#include <stdio.h>

int fac(int n);
 
int main()
{    
    int res = fac(5);
    printf("%d",res);
}

int fac(int n)
{
    if(n<0)
    {
        return -1;
    }
    else if(n==0 || n == 1){
        return 1;
    }
    else{
        return n*fac(n-1);
    }
}