#include <stdio.h>
#include <string.h>

#define N 1002
int c[N][N], b[N][N];

void LCSL(char s1[N], char s2[N], int len1, int len2);
void printl(char s1[N], char s2[N], int i, int j);
void printa(int v[N][N], int len1, int len2);

int main()
{
    int len1, len2;

    char s1[N] = "ABCADAB";
    char s2[N] = "BACDBA";
    len1 = strlen(s1) + 1;
    len2 = strlen(s2) + 1;
    for (int i = 0; i < len1; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 0; j < len2; j++)
    {
        c[0][j] = 0;
    }
    LCSL(s1, s2, len1, len2);
    printf("%s\n","b[][]");
    printa(b, len1,len2);
    printf("%s\n","c[][]");    
    printa(c,len1,len2);
    printf("%s\n","LCSL");
    printl(s1,s2,len1-1,len2-1);
}

void LCSL(char s1[N], char s2[N], int len1, int len2)
{
    int i, j;
    for (i = 1; i < len1; i++)
    {
        for (j = 1; j < len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else
            {
                if (c[i][j - 1] >= c[i - 1][j])
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 2;
                }
                else
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 3;
                }
            }
        }
    }
}

void printl(char s1[N], char s2[N], int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1)
    {
        printf("%d-%c:",i-1, s1[i-1]);
        printl(s1, s2, i - 1, j - 1);
    }
    else if (b[i][j] == 2)
    {
        printl(s1, s2, i, j - 1);
    }
    else
    {
        printl(s1, s2, i - 1, j);
    }
}

void printa(int v[N][N], int len1, int len2)
{
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}