#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int dp[10010][10];
int x[20005];
int psum[20005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=n;++i){
			scanf("%d",&x[i]);
		}
		for(int i=0;i<=n;++i)for(int j=0;j<5;++j)dp[i][j]=INF;
		dp[0][0]=0;
		for(int i=0;i<n;++i){
			dp[i+1][0]=min(dp[i+1][0],dp[i][0]+a*x[i+1]);
			dp[i+1][4]=min(dp[i+1][4],dp[i][0]+b);
			for(int j=1;j<5;++j){
				dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]);
			}	
		}
		int ans=INF;
		for(int i=0;i<5;++i)ans=min(ans,dp[n][i]);
		printf("%d\n",ans);
	}
}