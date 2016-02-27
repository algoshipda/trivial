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
int dp[20005];
int coin[105];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%d",&coin[i]);

	dp[0] = 1;
	for(i=0;i<N;++i)
		for(j=0;j<=K;++j){
			if(j+coin[i]>K)break;
			dp[j+coin[i]] += dp[j];
		}
	printf("%d\n",dp[K]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
