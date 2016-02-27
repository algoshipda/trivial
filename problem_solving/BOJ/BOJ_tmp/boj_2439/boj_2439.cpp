#include <cstdio>
int n;
void f(int k){
        if(k==0) return;
        f(k-1);
        for(int i=k;i<n;++i)printf(" ");
        for(int i=0;i<k;++i)printf("*");
        puts("");
}
int main(){
        scanf("%d",&n);
        f(n);
}
