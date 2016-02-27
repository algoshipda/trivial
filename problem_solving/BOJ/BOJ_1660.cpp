#include <bits/stdc++.h>
using namespace std;

int n,k;
int x[300];
int dp[300005];
int main()
{
	int s = 0;
	for(k=1;;++k){
		int w = k*(k+1)/2;
		s+=w;
		if(s>300000)break;
		x[k] = s;
	}

	scanf("%d",&n);
	for(int i=0;i<=n;++i)dp[i]=(int)1e9;
	dp[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<k;++j){
			if(i-x[j]<0)break;
			dp[i] = min(dp[i], dp[i-x[j]] + 1);
		}
	}
	printf("%d\n",dp[n]);
}
