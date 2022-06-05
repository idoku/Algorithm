#include <stdio.h>
#include <math.h>
#include <limits.h>

#define inf INT_MAX

#define N 100

int G[N][N] = {
    {inf, 23, inf, inf, inf, 28, 36},
    {23, inf, 20, inf, inf, inf, 1},
    {inf, 20, inf, 15, inf, inf, 4},
    {inf, inf, 15, inf, 3, inf, 9},
    {inf, inf, inf, 3, inf, 17, 16},
    {28, inf, inf, inf, 17, inf, 25},
    {36, 1, 4, 9, 16, 25, inf},
};
int S[N];
int closest[N];
int lowcost[N];

void Prim(int n, int u0, int g[N][N]);
void printg(int n);
void printa(int v[], int n);

int main()
{
    int n = 7, m, u, v, w;
    Prim(n, 0, G);
    printa(lowcost,n);
    printf("\n");
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=lowcost[i];
    }
    printf("%d",sum);
}

void Prim(int n, int u0, int g[N][N])
{
    int m, u, v, w;
    S[u0] = 1;
    // 1.初始化
    for (int i = 1; i < n; i++)
    {
        if (i != u0)
        {
            S[i] = 0;
            lowcost[i] = g[u0][i];
            closest[i] = 0;
        }
        else
        {
            lowcost[i] = 0;
        }
    }
    // printa(lowcost,7);
    // printf("\n");
    // printa(closest,7);
  

    for (int i = 0; i < n; i++)
    {
        int tmp = inf;
        int t = u0;
        // 2.找最小
        for (int j = 0; j < n; j++)
        {
            if ((!S[j]) && lowcost[j] < tmp)
            {
                t = j;
                tmp = lowcost[j];
            }
        }
        if(t==u0)
            break;
        S[t] = 1;
        //3.更新
        for (int j = 0; j < n; j++)
        {
            if((!S[j]) && (G[t][j]<lowcost[j])){
                lowcost[j] = G[t][j];
                closest[j] = t;
            }
        }        
    }

    
}

void printa(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

void printg(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("(%d,%d)=%d ", i, j, G[i][j]);
        }
        printf("\n");
    }
}