#include <stdio.h>
 
void swap(int *a,int *b);

int main()
{
	int a=5,b=4;
    swap(&a,&b);
    printf("%d %d",a,b);
	return 0;
}
 
void swap(int *a,int *b){
    int t; //t为辅助空间
    t = *a;
    *a = *b;
    *b = t;
}