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

int D,N;
int T[205];
int A[205];
int B[205];
int C[205];
int dp[205][205];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&D,&N);
	int i,j,k;
	for(i=0;i<D;++i)scanf("%d",&T[i]);
	for(i=0;i<N;++i)scanf("%d%d%d",&A[i],&B[i],&C[i]);
	int ans = 0;
	for(i=1;i<D;++i){
		for(j=0;j<N;++j){
			if(T[i]>B[j] || T[i]<A[j])continue;
			for(k=0;k<N;++k){
				if(T[i-1]>B[k] || T[i-1]<A[k])continue;
				dp[i+1][j] = max(dp[i+1][j], dp[i][k] + abs(C[k]-C[j]));
			}
		}
	}
	for(i=0;i<N;++i)ans=max(dp[D][i],ans);
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
