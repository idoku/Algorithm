#include <stdio.h>

int findx(int arr[],int len,int val);
 
int main()
{
    int arr[] = {9, 7, 5, 3, 1};
    int res = findx(arr,5,5);
    printf("%d",res);
}

int findx(int arr[],int len,int val)
{
      for (int i = 0; i < len; i++)
      {
          if(arr[i]==val){
              return i;
          }
      }
      return -1;      
}