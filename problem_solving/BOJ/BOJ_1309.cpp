#include <bits/stdc++.h>
using namespace std;

int n;
int dp[100005][3];
int main()
{
	scanf("%d",&n);
	dp[0][0]=1;
	for(int i=0;i<n;++i){
		dp[i+1][0]=(dp[i+1][0]+dp[i][0]+dp[i][1]+dp[i][2])%9901;
		dp[i+1][1]=(dp[i+1][1]+dp[i][0]+dp[i][2])%9901;
		dp[i+1][2]=(dp[i+1][2]+dp[i][0]+dp[i][1])%9901;
	}
	printf("%d\n",(dp[n][0]+dp[n][1]+dp[n][2])%9901);
}
