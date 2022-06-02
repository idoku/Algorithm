/*
数组中有99个元素,1~100集合中抽取99个数保存到数组,找出集合中剩余的数值.
*/

using System;
using System.Linq;

var arr = GetRandomArray();
int guessTotal = 55;
for (int i = 0; i < 9; i++)
{
    Console.Write(arr[i]+ " ");
    guessTotal -=arr[i];
}
Console.Write("\n\r"+guessTotal+ " ");



static int[] GetRandomArray(){
    int num = 10;
    Random random = new Random();    
     int[] mat = new int[num];
     int i, p=0, tmp=0;
     for(i=0;i<num;i++)
         mat[i] = i+1;
     for (i = num-1; i >= 0;i-- )
     {
         p = random.Next(0, i);
         tmp = mat[p];
         mat[p] = mat[i];
         mat[i] = tmp;
     }
     return mat;
}