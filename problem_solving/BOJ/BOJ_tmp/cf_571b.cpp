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
int arr[300005];
int dp[3][5005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%d",&arr[i]);
	sort(arr,arr+N);
	for(i=0;i<=N;++i)for(j=0;j<=K;++j)dp[i][j]=INF;
	dp[0][0] = 0;
	for(i=0;i<N-1;++i){
		for(j=1;j<=K && j<=i;++j)
			dp[2][j] = min(arr[i+1]-arr[i] + dp[0][j-1],dp[1][j]);
		swap(dp[1],dp[2]);
		swap(dp[0],dp[1]);
	}
	printf("%d\n",dp[2][K]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
