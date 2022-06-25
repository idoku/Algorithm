#include <stdio.h>

int  binary_search(int x, int v[], int low,int high);


int main(int argc, char const *argv[])
{
	int arr[] = {1, 3, 5, 7, 9};
	printf("%d\n", binary_search(7, arr,0, 5));
    printf("%d\n", binary_search(4, arr,0,5));
	return 0;
}

int binary_search(int x, int v[], int low,int high)
{
	if(low>high)
		return -1;
	int mid = (low + high) / 2;
    if(x==v[mid])
		return mid;
	else if(x<v[mid])
		return binary_search(x,v,low,mid-1);
	else 
		return binary_search(x,v,mid+1,high);
}