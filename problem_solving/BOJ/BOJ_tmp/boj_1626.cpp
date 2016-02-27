#include <cstdio>

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;++i){
        for(int j=1;j<=i;++j)
            printf("%c",'*');      
        puts("");
    }
    for(int i=N-1;i>=1;--i){
        for(int j=i;j>=1;--i)
            printf("%c",'*');
        puts("");
    }
    
}
