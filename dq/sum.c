#include <stdio.h>

int sum(int v[],int n);

int main(){
    int arr[] = {2,4,6};
    int res = sum(arr,3);
    printf("%d",res);
}

int sum(int v[],int n){
     
     if(n==0)
      return 0;
     else{
        int val = v[n-1];       
        return val+ sum(v,n-1);
     }
}