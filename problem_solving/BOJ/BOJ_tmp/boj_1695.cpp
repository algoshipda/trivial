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

int N;
int seq[5005];
int dp[5005][5005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int i,j,k;
	scanf("%d",&N);
	for(i=0;i<N;++i)scanf("%d",&seq[i]);
	for(i=0;i<=N;++i)for(j=0;j<=N;++j)dp[i][j]=INF;
	for(i=N-1;i>=0;--i)for(j=i;j<N;++j){
		if(i==j)dp[i][j]=0;
		else if(i+1==j && seq[i]==seq[j])dp[i][j] = 0;
		else{
			if(seq[i]==seq[j]) dp[i][j] = dp[i+1][j-1];
			dp[i][j] = min(dp[i][j],1 + min(dp[i+1][j],dp[i][j-1]));
		}
	}
	printf("%d\n",dp[0][N-1]);
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
