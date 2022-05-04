#include <stdio.h>
#include <Windows.h>


void printa(int v[],int n);
void printb(int v[],int n);



void printa(int v[],int n){
    for (int i = 0; i < n; i++)
    printf("%d", v[i]);
    printf("\n");
}

void printb(int v[],int n){
    for (int i = 0; i < n; i++)
    printf("%d", v[i]);
    printf("\n");
    sleep(1);
}
