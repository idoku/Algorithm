#include <stdio.h>

int fib(int n);
 
int main()
{    
    int res = fib(5);
    printf("%d\n",res);
 
}
 

int fib(int n){
    if(n == 1 || n == 2)
        return 1;
    int s1,s2;
    s1 = 1;
    s2 = 1;
    for (int i = 3; i <= n; i++)
    {
        s2 = s1 + s2;
        s1 = s2 - s1;
    }    
    return s2;
}

 