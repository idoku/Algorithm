#include <stdio.h>

void qsort(int v[],int left,int right);
void swap(int v[],int i,int j);
void printa(int v[],int n);

int main(int argc, char const *argv[])
{
	int arr[] = {9, 7, 5,3,1};
    printa(arr,5);
    qsort(arr,0,4);
    printa(arr,5);
	return 0;
}


/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(int v[],int left,int right)
{
	int i,last;
	void swap(int v[],int i,int j); 
	if(left>=right) /* do nothing if array contains */
		return; /* fewer than two elements */
	swap(v,left,(left+right)/2); /* move partition elem */
	last = left;	/* to v[0] */
	for(i = left+1;i<=right;i++){ /* partition */	
		if(v[i]<v[left])
			swap(v,++last,i);
	}
	swap(v,left,last); /* restore partition elem */
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}

/* swap:interchange v[i] and v[j] */
void swap(int v[],int i,int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void printa(int v[],int n){
    for (int i = 0; i < n; i++)
    printf("%d", v[i]);
    printf("\n");
}