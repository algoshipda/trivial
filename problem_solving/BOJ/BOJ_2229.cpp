#include <bits/stdc++h>
using namespace std;

int n;
int a[1005];
int dp[1005];
int dis[1005][1005];

int rec(int x)
{
	int& ret = dp[x];
	if(ret!=-1)return ret;
	ret = 0;
	for(int i=0;i<x;++i){
		ret = max(ret, rec(i)+dis[i+1][x]);
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;++i){
		int m = (int)1e9;
		int M = 0;
		for(int j=i;j<=n;++j){
			m = min(m,a[j]);
			M = max(M,a[j]);
			dis[i][j]=M-m;	
		}
	}
	printf("%d\n",rec(n));
}


