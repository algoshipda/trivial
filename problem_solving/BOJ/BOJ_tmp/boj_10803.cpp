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

int N,M;

int dp[10002][102];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&M);
	int i,j,k;
	if(N<M)swap(N,M);
	for(i=1;i<=N;++i)
		for(j=1;j<=N;++j)
			dp[i][j] = INF;
		
	
	
	for(i=1;i<=M;++i)dp[i][i]=1;
	dp[1][1]=1;
	for(i=1;i<=N;++i){
		for(j=1;j<=M;++j){
			if(i==j)continue;
			for(k=1;k<i && k<=M;++k)dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
			for(k=1;k<j;++k)dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]);			
		}
	}
	printf("%d\n",dp[N][M]);
		
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
