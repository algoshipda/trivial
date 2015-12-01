#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n,k;
int cnt[2][100005];
int dp[2][100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i){
			int x;
			scanf("%d",&x);
			cnt[0][i]=cnt[1][i]=0;
			while(x && x%2==0){
				x/=2;
				cnt[0][i]++;
			}
			while(x && x%5==0){
				x/=5;
				cnt[1][i]++;
			}
		}
		for(int i=2;i<=n;++i)dp[0][i]=dp[1][i]=INF;
		dp[0][1]=cnt[0][1];
		dp[1][1]=cnt[1][1];
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k;++j){
				dp[0][i+j]=min(dp[0][i+j],dp[0][i]+cnt[0][i+j]);
				dp[1][i+j]=min(dp[1][i+j],dp[1][i]+cnt[1][i+j]);
			}
		}
		printf("%d\n",min(dp[0][n],dp[1][n]));
	}
}
