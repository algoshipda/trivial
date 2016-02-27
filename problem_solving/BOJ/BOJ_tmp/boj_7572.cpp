#include <cstdio>

char c[15] = "ABCDEFGHIJKL";
char b[15] = "01234567890";
int main()
{
        int n;
        scanf("%d",&n);
        n+=56;
        n%=60;
        printf("%c%c\n",c[n%12],b[n%10]);
}       
