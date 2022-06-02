#include <stdio.h>
#include <limits.h>

#define N 100
#define INF INT_MAX

int map[N][N] = {
    {INF, 2, 5, INF, INF},
    {INF, INF, 2, 6, INF},
    {INF, INF, INF, 7, 1},
    {INF, INF, 2, INF, INF},
    {INF, INF, INF, INF, INF},
};
int dist[N], flag[N], p[N], n, m;

void dijkstra(int u);
void findpath(int u);

int main()
{
    n = 5;
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        if(dist[i]==INF)
            printf("fail\n");
        else{
            printf("%d ,shortest path: %d\n",i,dist[i]);
        }
    }
    
}

//留findpath待实现

void dijkstra(int u)
{

    for (int i = 0; i < n; i++)
    {
        // 1.初始化dist,源点u到各个顶点的最短路径长度
        dist[i] = map[u][i];

        if (dist[i] == INF)
        {
            p[i] = -1; //源点u到该顶点长度无穷大,说明顶点i与源点u不相邻
        }
        else
        {
            p[i] = u; //说明顶点i与源点u相邻,设置顶点i的前驱p[i]=u
        }
    }
    dist[u] = 0;
    flag[u] = 1;

    for (int i = 0; i < n; i++)
    {
        int tmp = INF, t = u;
        for (int j = 0; j < n; j++)
        {
            if (!flag[j] && dist[j] < tmp)
            {
                t = j;
                tmp = dist[j];
            }
        }
        if (t == u)
            return;
        flag[t] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!flag[j] && map[t][j] < INF)
            {
                if (dist[j] > (dist[t] + map[t][j]))
                {
                    dist[j] = dist[t] + map[t][j];
                    p[j] = t;
                }
            }
        }
    }
}
