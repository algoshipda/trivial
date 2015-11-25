#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int m=0;
        int M=0;
        int n;
        scanf("%d",&n);
        int sum=0;
        int cm=0;
        int cM=0;
        for(int i=1;i<=n;++i){
            int x;
            scanf("%d",&x);
            sum+=x;
            cm=min(x,cm+x);
            cM=max(x,cM+x);
            m=min(m,cm);
            M=max(M,cM);
        }
        printf("%d\n",max(M,sum-m));
    }
}
