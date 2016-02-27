#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n;
int lcs[5005][5005];
int psum[5005][5005];
int dp[5005][5005];

char str[5005];
int main()
{
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=n-1;i>=0;--i){
		for(int j=n-1;j>=i+1;--j){
			if(str[i]!=str[j])continue;
			lcs[i][j]=1;
			if(i+1<j+1){
				lcs[i][j]+=lcs[i+1][j+1];
			}
		}
	}
	dp[0][n]=psum[0][n]=1;
	int ans=1;
	for(int i=n-1;i>=1;--i){
		if(str[n-i]!='0')dp[n-i][i]=psum[n-i][i]=1;
		for(int j=n-i-1;j>=0;--j){
			if(str[j]!='0'){
				int k=lcs[j][j+i];
				if(k<i && j+2*i<=n && str[j+k]<str[j+i+k]){
					dp[j][i]=dp[j+i][i];
				}
				dp[j][i]=(dp[j][i]+psum[j+i][i+1])%MOD;
			}
			psum[j][i]=(dp[j][i]+psum[j][i+1])%MOD;
		}
		ans=(ans+dp[0][i])%MOD;
	}
	printf("%d\n",ans);
}
