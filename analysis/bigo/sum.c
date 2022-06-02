#include <stdio.h>

int sum(int n);
 
int main()
{
    int res = sum(10);
    printf("%d",res);
}

int sum(int n)
{
      int sum = 0; //运行1次
     int total = 0; //运行1次
     for(int i=1;i<=n;i++){ //运行n+1次
         sum = sum+i; //运行n次
         for(int j=1;j<=n;j++){ // 运行n*(n+1)次
            total = total+i*j; // 运行n*n次
         }
     }
     return total;
}