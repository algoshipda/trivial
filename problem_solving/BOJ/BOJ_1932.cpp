#include <bits/stdc++.h>
using namespace std;

int n;
int dp[505][505];
int a[505][505];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			scanf("%d",&a[i][j]);
		}
	}
	dp[1][1]=a[1][1];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i+1][j]);
			dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+a[i+1][j+1]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,dp[n][i]);
	}
	printf("%d\n",ans);
}
