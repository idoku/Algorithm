#include <stdio.h>

int sum(int arr[],int n);

int main(){
    int arr[] = {2,4,6};
    int res = sum(arr,3);
    printf("%d",res);
}

int sum(int arr[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    return sum;
}