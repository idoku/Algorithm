#include <stdio.h>

#define M 100

typedef struct Node
{
    int S[M];
    int l;
    int c;
} node, *pNode;

void init(int n, pNode des);
void mul(pNode pa, pNode pb, pNode ans);
void cp(pNode src, pNode des, int st, int l);
void add(pNode pa, pNode pb, pNode ans);
void swap(pNode pa, pNode pb);
void printn(pNode p);

int main()
{
    int a = 123, b = 41;
    node sa, sb,ans;
    init(a, &sa);
    init(b, &sb);
    printn(&sa);
    printn(&sb);

   
    //add(&sa,&sb,&ans);    
    // printn(&ans);

    // int ma = sa.l/2;
    // node ah,al;
    // cp(&sa,&ah,ma,sa.l-ma);    
    // printn(&ah);
    // cp(&sa,&al,0,ma);
    // printn(&al);
        
    // mul(&ah,&al,&ans);
    // printn(&ans);

    mul(&sa,&sb,&ans);
    printn(&ans);

}

void init(int n, pNode des)
{
    int i = 0;
    while (n != 0)
    {
        des->S[i++] = n % 10;
        n /= 10;
    }
    des->l = i;
    des->c = 0;
}

void mul(pNode pa, pNode pb, pNode ans)
{
   
    int ma = pa->l/2, mb = pb->l/2;

    node ah, al, bh, bl, z;
    node t1, t2, t3, t4;
    int i, cc, w;
    if (!ma || !mb)
    {
        if (!ma)
        {
            swap(pa, pb);
        }
        ans->c = pa->c + pb->c;
        w = pb->S[0];
        cc = 0;
        for (i = 0; i < pa->l; i++)
        {
            ans->S[i] = (w * pa->S[i] + cc) % 10;
            cc = (w * pa->S[i] + cc) / 10;
            //printf("ans=%d,cc=%d\n",ans->S[i],cc);
        }
        if (cc)
            ans->S[i++] = cc;
        ans->l = i;
        return;
    }

    //分治核心
     cp(pa, &ah, ma, pa->l-ma);
     cp(pa, &al, 0, ma);
     cp(pb, &bh, mb, pb->l-mb);
     cp(pb, &bl, 0, mb);

     mul(&ah, &bh, &t1);
     mul(&ah, &bl, &t2);
     mul(&al, &bh, &t3);
     mul(&al, &bl, &t4);

     add(&t3, &t4, ans);
     add(&t2, ans, &z);
     add(&t1, &z, ans);
}

void cp(pNode src, pNode des, int st, int l)
{
    for (int i = st, j = 0; i < st + l; i++, j++)
    {
        des->S[j] = src->S[i];
    }
    des->l = l;
    des->c = st + src->c;
}

void add(pNode pa, pNode pb, pNode ans)
{
    if (pa->c < pb->c)
    {      
        swap(pa, pb);
    }
    ans->c = pb->c;
    int cc = 0, len = 0;
    int k = pa->c - pb->c;
    int alen = pa->l + pa->c;
    int blen = pb->l + pb->c;
    if (alen > blen)
    {
        len = alen;
    }
    else
    {
        len = blen;
    }
    len = len - pb->c;
    int i,ta, tb;       
    for ( i = 0; i < len; i++)
    {
        if (i < k)
        {
            ta = 0;
        }
        else
        {
            ta = pa->S[i - k];
        }

        if (i < pb->l)
        {
            tb = pb->S[i];
        }
        else
        {
            tb = 0;
        }

        if (i >= pa->l + k)
        {
            ta = 0;
        }
      
        ans->S[i] = (ta + tb + cc) % 10;      
        cc = (ta + tb + cc) / 10;
        //printf("s=%d,cc=%d\n",ans->S[i],cc);
    }
    if(cc){
       
        ans->S[i++]=cc;
    }        
        ans->l=i;
}

void swap(pNode pa, pNode pb)
{
    pNode t;
    t = pa;
    pa = pb;
    pb = t;
}

void printn(pNode p)
{
    for (int i = 0; i < p->l; i++)
    {
        printf("%d ", p->S[i]);
    }
    printf("\nl=%d, c=%d\n",p->l, p->c);
}