#include <stdio.h>
#include <math.h>

int prime(int k);
int prime2(int k);
int prime3(int k);
void printa(int v[], int n);

int main()
{
    for (int i = 0; i < 50; i++)
    {

        int res = prime(i);
        printf("%d=%d ", i, res);
        res = prime2(i);
        printf("%d=%d ", i, res);
        res = prime3(i);
        printf("%d=%d \n", i, res);
    }
}

int prime(int k)
{
    if (k <= 1)
    {
        return 0;
    }
    else if (k == 2)
    {
        return 1;
    }
    for (int i = 2; i < k; i++)
    {
        if (k % i == 0)
            return 0;
    }
    return 1;
}

int prime2(int k)
{
    if (k <= 1)
    {
        return 0;
    }
    else if (k == 2)
    {
        return 1;
    }
    int j = (int)sqrt((double)k);
    int i = 2;
    while (i <= j)
    {
        if (k % i == 0)
        {
            return 0;
        }
        i++;
    }

    return 1;
}

int prime3(int k)
{
    if (k <= 1)
    {
        return 0;
    }
    else if (k == 2)
    {
        return 1;
    }
    if (k % 2 == 0)
    {
        return 0;
    }
    else
    {
        int j = (int)sqrt((double)k) + 1;
        for (int i = 3; i < j; i = i + 2)
        {
            if (k % i == 0)
                return 0;
        }
        return 1;
    }
}