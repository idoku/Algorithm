#include <stdio.h>

void mod();
void mod2();

int main()
{    
      mod();
      mod2();
}

void mod()
{
     int n = 1;
    while (!((n%2==1) && (n%3==2) && (n%5==4)&& (n%6==5)&& (n%7==0)))
    {
        n++;
    }
    printf("n = %d \n",n);  
}

void mod2()
{
     int n = 7;
    while (!((n%2==1) && (n%3==2) && (n%5==4)&& (n%6==5)&& (n%7==0)))
    {
        n = n+7;
    }
    printf("n = %d \n",n);  
}