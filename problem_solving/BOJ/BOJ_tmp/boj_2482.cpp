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
const int MOD = 1000000003;
int N,K;
int dp[1003][1003];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	int i,j,k;
	if(K==1){
		printf("%d\n",N);
		return 0;
	}
	for(i=0;i<=N;++i)dp[i][0] = 1;
	for(i=1;i<=N;++i)dp[i][1] = i;
	for(i=2;i<=N;++i){
		for(j=1;j<=K;++j){
			dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%MOD;
		}
	}
	printf("%d\n",((dp[N][K]-dp[N-4][K-2])%MOD+MOD)%MOD);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
