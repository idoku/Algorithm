#include <stdio.h>

int binary_search(int x, int v[], int n);

int main(int argc, char const *argv[])
{
	int arr[] = {1, 3, 5, 7, 9};
	printf("%d\n", binary_search(7, arr, 5));
	printf("%d\n", binary_search(7, arr, 11));
	return 0;
}

int binary_search(int x, int v[], int n)
{
	int mid, low = 0, high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (v[mid] > x)
		{
			high = mid - 1;
		}
		else if (v[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}