#include <bits/stdc++.h>
using namespace std;

int n;
int num[100005];
int dp[100005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&num[i]);
	dp[1]=dp[n-1]=1;
	for(int i=1;i<n-1;++i){
		dp[i]=min(dp[i-1]+1,num[i]);
	}
	for(int i=n-2;i>0;--i){
		dp[i]=min(dp[i],min(dp[i+1]+1,num[i]));
	}
	printf("%d\n",*max_element(dp,dp+n));
}