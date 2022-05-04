#include <stdio.h>

int b_search(int v[],int l,int r, int x);

int main(int argc, char const *argv[])
{
	int arr[] = {1, 3, 5, 7, 9};
	printf("%d\n", b_search(arr,0,4, 5));
	printf("%d\n", b_search(arr,0,4, 11));
	return 0;
}

int b_search(int v[],int l,int r, int x)
{
	if(r > l){
        int mid = (r+l) / 2 ;
        if(v[mid]== x){
            return mid;
        }
    
        if(v[mid] > x)
            return b_search(v,l,mid-1,x);
        
        return b_search(v,mid+1,r,x);
        
    }
	return -1;
}