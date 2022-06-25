#include <stdio.h>

void quick_sort(int v[], int left, int right);
int partition(int v[], int l, int r);
void printa(int v[], int n);
void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
    int arr[] = {9, 7, 5, 3, 1};
    printa(arr, 5);
    quick_sort(arr, 0, 4);
    printa(arr, 5);
    return 0;
}

void quick_sort(int v[], int left, int right)
{
    int q;
    if (left < right) /* do nothing if array contains */
    {
        q = partition(v, left, right);
        quick_sort(v, left, q - 1);
        quick_sort(v, q + 1, right);
    }
}

int partition(int v[], int l, int r)
{
    int i = l, j = r, povit = v[l];
    while (i < j)
    {
        while (i < j && v[j] > povit)
        {
            j--;
        }
        if (i < j)
            swap(&v[i++], &v[j]);
        while (i < j && v[i] <= povit)
        {
            i++;
        }
        if (i < j)
            swap(&v[i], &v[j--]);
    }   
    return i;
}

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void printa(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", v[i]);
    printf("\n");
}