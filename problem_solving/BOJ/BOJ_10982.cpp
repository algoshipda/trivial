#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int S=100000;
int a[1005];
int b[1005];
int dp[2][200005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int l=0,r=0;
        for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
        
        for(int i=0;i<=200000;++i)dp[0][i]=dp[1][i]=INF;
        dp[0][S]=0;
        for(int i=1;i<=n;++i){
            for(int j=S-l;j<=S+r;++j){
                int x,y;
                if(j<S){
                    x=dp[0][j]-(S-j);
                    y=dp[0][j];
                }else{
                    x=dp[0][j];
                    y=dp[0][j]-(j-S);
                }
                dp[1][x+a[i]-y+S]=min(dp[1][x+a[i]-y+S],max(x+a[i],y));
                dp[1][x-(y+b[i])+S]=min(dp[1][x-(y+b[i])+S],max(x,y+b[i]));
            }
            r+=a[i];
            l+=b[i];
            for(int j=S-l;j<=S+r;++j){
                dp[0][j]=dp[1][j];
                dp[1][j]=INF;
            }
        }
        int ans=INF;
        for(int i=S-l;i<=S+r;++i){
            ans=min(ans,dp[0][i]);
        }
        printf("%d\n",ans);
    }
}
