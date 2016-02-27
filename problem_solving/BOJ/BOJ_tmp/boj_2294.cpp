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

int N,K;
int coin[102];
int dp[10004];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%d",&coin[i]);

	for(i=0;i<=K;++i)dp[i]=INF;
	dp[0] = 0;
	for(i=0;i<N;++i)
		for(j=0;j<=K;++j){
			if(j+coin[i]>K)continue;
			dp[j+coin[i]] = min(dp[j+coin[i]],dp[j]+1);
		}
	printf("%d\n",dp[K]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
