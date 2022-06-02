#include <stdio.h>

int main()
{    
    int x,y,z;
    for (x = 1; x <= 9; x++)
    {
         y = 20 - 2*x;
         z = 30 - x - y;
         printf("x = %d ,y = %d, z = %d\n",x,y,z);
    }  
}