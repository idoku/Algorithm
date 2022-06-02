#include <stdio.h>
#include <string.h>
int is_palindrome(char *s);
void printa(int v[],int n);
void swap(int *a,int *b);

int main(int argc, char const *argv[])
{
	char *s = "abcba";        
    
    printf("%d\n",is_palindrome(s));
    s = "abac";
    printf("%d\n",is_palindrome(s));    
	return 0;
}

int is_palindrome(char *s)
{    
    int len = strlen(s);
    for (int i = 0; i < len/2; i++)
    {
        if(s[i]!=s[len-1-i])
         return 0;
         else
         return 1;
    }
    

}
  