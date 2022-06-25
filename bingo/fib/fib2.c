#include <stdio.h>

int fib(int n);
int fib3(int n);
void printa(int v[],int n);

int main()
{    
    int res = fib(5);
    printf("%d\n",res);  
}



int fib(int n){
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2;i<n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n-1];
}
