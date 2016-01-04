#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005];
int b[1005];
int dp[1005][1005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]);
	if(n<m){
		swap(n,m);
		swap(a,b);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)dp[i][j]=(int)1e9;
	dp[0][0]=0;
	for(int j=0;j<=m;++j){
		for(int i=0;i<=n;++i){
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(a[i+1]-b[j+1]));
		}
	}
	printf("%d\n",dp[n][m]);
}

