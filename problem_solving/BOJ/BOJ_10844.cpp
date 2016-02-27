#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9;
int n;
int dp[105][10];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=9;++i)dp[1][i]=1;
	for(int i=1;i<n;++i){
		for(int j=0;j<=9;++j){
			if(j)dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%MOD;
			if(j<9)dp[i+1][j+1]+=(dp[i+1][j+1]+dp[i][j])%MOD;
		}
	}
	int ans=0;
	for(int i=0;i<=9;++i){
		ans=(ans+dp[n][i])%MOD;
	}
	printf("%d\n",ans);
}
