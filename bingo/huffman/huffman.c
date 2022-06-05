#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

 
 
#define MAXBIT 6
#define MAXLEAF 8
#define MAXVAL DBL_MAX

typedef struct tree
{
    double weight;
    int parent;
    int lchild;
    int rchild;
    char value;
} HNode;


typedef struct code
{
    int bit[MAXBIT];
    int start;
} HCode;

void Huffman(HNode hnode[],int n);
void HuffmanCode(HNode hnode[],HCode hcode[],int n);
void printh(HNode v[],int n);
void printc(HCode code,int n);

void printhc(HNode v[],HCode t[],int n);

int main()
{            
     HNode hnode[11] = {{5,-1,-1,-1,'a'},
     {32,-1,-1,-1,'b'},
     {18,-1,-1,-1,'c'},
     {7,-1,-1,-1,'d'},
     {25,-1,-1,-1,'e'},
     {13,-1,-1,-1,'f'},
     {0,-1,-1,-1,' '},
     {0,-1,-1,-1,' '},
     {0,-1,-1,-1,' '},
     {0,-1,-1,-1,' '},
     {0,-1,-1,-1,' '}};
     //printh(hnode,10);
     Huffman(hnode,6);
     printh(hnode,11);
     HCode hcode[6] ;
     HuffmanCode(hnode,hcode,6);
    printhc(hnode,hcode,6);
}

void Huffman(HNode hnode[],int n)
{
    int t,x1,x2;
    double m1,m2;
    for (int i = 0; i < n-1; i++)
    {
        m1 = m2 = MAXVAL; // 两个最小权值
        x1 = x2 = -1; //两个最小权值序号
         
        for (int j = 0; j < n+i; j++)
        {
            if(hnode[j].weight < m1 && hnode[j].parent == -1){
               
                    m2 = m1;
                    m1 = hnode[j].weight;
                    x2 = x1;
                    x1 =j;
            }else if(hnode[j].weight<m2 &&  hnode[j].parent == -1){
                    m2 = hnode[j].weight;
                    x2 = j;
            }
        }
        t= n+i;
        //printf("x1=%d,x2=%d,m1=%0.2f,m2=%0.2f, %d\n",x1,x2,m1,m2,t);
        hnode[x1].parent = t;
        hnode[x2].parent = t;
        hnode[t].weight = m1+m2;
        hnode[t].lchild = x1;
        hnode[t].rchild = x2;
    }
    
    
}

void HuffmanCode(HNode hnode[],HCode hcode[],int n)
{
    HCode tCode;
    int c,p;
    for (int i = 0; i < n; i++)
    {
        tCode.start = n-1;       
        c = i; //叶子节点
        p =  hnode[c].parent;
        while (p!=-1)
        {
            if(hnode[p].lchild==c){
                tCode.bit[tCode.start] = 0;
                //printf("%d,%d\n",i,tCode.bit[tCode.start]);
            }
            else{
                tCode.bit[tCode.start]=1;
                //printf("%d,%d\n",i,tCode.bit[tCode.start]);
            }               
            tCode.start--;
            c = p; //c,p变量上移,准备下一个循环
            p = hnode[c].parent;
        };
        //printc(tCode,6);
        //printf("\n");        
        for (int j = tCode.start+1; j < n; j++)
        {
             hcode[i].bit[j] = tCode.bit[j];             
        }
        hcode[i].start = tCode.start;
        // printc(hcode[i],6);
        // printf("\n");
    }    
}


void printh(HNode v[],int n){
    for (int i = 0; i < n; i++)
    printf("i=%d:weight=%0.2f,p=%d,l=%d,r=%d,char=%c\n", i,v[i].weight,v[i].parent,v[i].lchild,v[i].rchild,v[i].value);
    printf("\n");
}

void printc(HCode code,int n)
{
      for (int i = code.start+1; i < n; i++)
      {
            printf("%d ",code.bit[i]);
      }
}

void printhc(HNode v[],HCode t[],int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c:code is :",v[i].value);
        for (int j = t[i].start+1; j < n; j++)
        {
            printf("%d",t[i].bit[j]);
        }
        printf("\n");
    }    
}
 