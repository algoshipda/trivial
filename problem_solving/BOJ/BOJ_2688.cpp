#include <stdio.h>

long long dp[66][10];
int main()
{
	int t;
	for(int i=0;i<10;++i)dp[1][i]=1;
	for(int i=2;i<=64;++i){
	    for(int j=0;j<10;++j){
		for(int k=0;k<=j;++k){
		    dp[i][k]+=dp[i-1][j];
		}
	    }
	}
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",dp[x+1][0]);		
	}
}
