#include <bits/stdc++.h>
using namespace std;

int n;
int a[2005];
int dp[2005][2005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)dp[i][j]=2e9+100;
	dp[0][0]=0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			int m=min(max(i,j)+1,n);
			dp[m][j]=min(dp[m][j],dp[i][j]+(i?abs(a[i]-a[m]):0));
			dp[i][m]=min(dp[i][m],dp[i][j]+(j?abs(a[j]-a[m]):0));
		}
	}
	int ans=2e9+100;
	for(int i=0;i<=n;++i){
		ans=min({ans,dp[i][n],dp[n][i]});
	}
	printf("%d\n",ans);
}
