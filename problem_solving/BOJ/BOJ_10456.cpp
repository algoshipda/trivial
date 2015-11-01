#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int plan[10055][2];
int dp[10055][35];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%d%d",&plan[i][0],&plan[i][1]);
            plan[i][1]<<=1;
        }
        for(int i=0;i<=n;++i)for(int j=0;j<30;++j)dp[i][j]=INF;
        dp[0][0]=0;
        for(int i=0;i<n;++i){
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+plan[i+1][0]+plan[i+1][1]);
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+plan[i+1][1]+3);
            dp[i+1][6]=min(dp[i+1][6],dp[i][0]+plan[i+1][1]+18);
            dp[i+1][29]=min(dp[i+1][29],dp[i][0]+plan[i+1][1]+45);
            for(int j=0;j<30;++j){
                int k=max(0,j-1);
                int l=min(i+1,n);
                dp[l][k]=min(dp[l][k],dp[i][j]+6);
                if(j)dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+plan[i+1][1]);
                k=max(0,j-7);
                l=min(i+7,n);
                dp[l][k]=min(dp[l][k],dp[i][j]+36);
                k=max(0,j-30);
                l=min(i+30,n);
                dp[l][k]=min(dp[l][k],dp[i][j]+90);
            }
        }
        int ans=INF;
        for(int i=0;i<30;++i)ans=min(ans,dp[n][i]);
        printf("%d\n",ans);
    }    
}