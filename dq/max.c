#include <stdio.h>

int max(int v[],int n);
void swap(int *a,int *b);

int main(){
    int arr[] = {2,6,4,3};
    int res = max(arr,3);
    printf("%d",res);
}

int max(int v[],int n){
     
     if(n == 1)
      return v[n-1]> v[n] ? v[n-1]:v[n];
     else{     
        if(v[n]>v[n-1])
             swap(&v[n],&v[n-1]);  
        return max(v,n-1);
     }
}

void swap(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
