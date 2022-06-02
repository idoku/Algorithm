#include <stdio.h>

int fib(int n);
int fib2(int n);
int fib3(int n);
void printa(int v[],int n);

int main()
{    
    int res = fib(5);
    printf("%d\n",res);
    res = fib2(5);
    printf("%d\n",res);
      res = fib3(5);
    printf("%d\n",res);
}

int fib(int n)
{
    if(n==1 || n == 2)
    {
        return 1;
    }   
    else{
        return fib(n-1)+fib(n-2);
    }
}

int fib2(int n){
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2;i<n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n-1];
}

int fib3(int n){
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

 