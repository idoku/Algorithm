#include <stdio.h>
#include <math.h>

#define MAX_PRIME_SIZE 302

int gb(int n);
int gb2(int p[],int n);
int is_prime(int k);
int binary_search(int x, int v[], int n);
void printa(int v[],int n);

int main()
{    
    //gb(100);
    int p[MAX_PRIME_SIZE],j=0;
    for (int i = 2; i < 2000; i++)
    {
         if(is_prime(i))
            p[j++]=i;
    }    
    printa(p,MAX_PRIME_SIZE);
    gb2(p,2000);
}


int gb(int n)
{
    for (int i = 4; i <= n; i+=2)
    {
        int j;
        for (j=2;j < i; j++)
        {
              if(is_prime(j)){
                   int k = i - j;
                   if(is_prime(k)){
                       printf("%d = %d + %d \n",i,j,k);
                       break;
                   }
              }
        }
        if(j==i){
            printf("error\n");
        }
    }
    
}
 

 int gb2(int p[],int n){
     for (int i = 4; i <= n; i+=2)
     {
         int j;
         for (j=2; j < i; j++)
         {
             if(binary_search(j,p,MAX_PRIME_SIZE)!=-1){
                  int k = i - j;
                   if(binary_search(k,p,MAX_PRIME_SIZE)!=-1){
                       printf("%d = %d + %d \n",i,j,k);
                       break;
                   }
             }
         }
          if(j==i){
            printf("error\n");
        }
     }     
 }

int is_prime(int k)
{
    if(k<=1){
        return 0;
    }
    else if(k==2){
      return 1;
    }
    int j = (int)sqrt((double)k);  
    int i=2;
    while (i<=j)
    {        
        if(k%i==0){
            return 0;
        }   
        i++;     
    }
    return 1;
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


void printa(int v[],int n){
    for (int i = 0; i < n; i++)
    printf("%d ", v[i]);
    printf("\n");
}