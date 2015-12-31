#include <bits/stdc++.h>
using namespace std;

int a[105];
int n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;j+=i){
                a[j]^=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            ans+=a[i];
        }
        printf("%d\n",ans);
    }
}
