#include <bits/stdc++.h>
using namespace std;
int t,w;
int a[1005];
int dp[1005][2][35];
int main()
{
	scanf("%d%d",&t,&w);
	for(int i=1;i<=t;++i){
		scanf("%d",&a[i]);
		--a[i];
	}
	for(int i=0;i<t;++i){
		for(int j=0;j<2;++j){
			for(int k=0;k<=w;++k){
				dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + (a[i+1] == j));
				dp[i+1][j^1][k+1] = max(dp[i+1][j^1][k+1],dp[i][j][k] + (a[i+1] == (j^1)));
			}
		}
	}
	printf("%d\n",max(dp[t][0][w],dp[t][1][w]));
}
