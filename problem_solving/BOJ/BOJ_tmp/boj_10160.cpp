#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;
const int MOD = 1000000009;
int N,K;
int dp[2][10];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	int i,j,k;
	dp[0][0] = 1;
	for(i=0;i<N;++i){
		dp[1][0] = ((K-1)*((lld)dp[0][0]) + 
					(K-2)*((lld)dp[0][1] + dp[0][2] + dp[0][3] + dp[0][4] + dp[0][6] + dp[0][7])%MOD)%MOD;
		dp[1][1] = ((lld)dp[0][0] + dp[0][1] + dp[0][3] +dp[0][4] + dp[0][6])%MOD;
		dp[1][2] = dp[0][1];
		dp[1][3] = dp[0][2];
		dp[1][4] = dp[0][3];
		dp[1][6] = (dp[0][2] + dp[0][7])%MOD;
		dp[1][7] = dp[0][6];
		swap(dp[1],dp[0]);
	}
	int ans = 0;
	for(i=0;i<10;++i){
		ans += dp[0][i];
		ans %= MOD;
	}
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
