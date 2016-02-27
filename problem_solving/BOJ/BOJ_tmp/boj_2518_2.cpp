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

int cnt[3];
int a[3][105];
int dp[105][105][105][3];


int N;
int NN;
int NNN;
int cost(int a, int b)
{
	return min(abs(a-b),NNN-(abs(a-b)));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k,x,y;
	for(i=0;i<3;++i){
		scanf("%d",&cnt[i]);
		for(j=1;j<=cnt[i];++j)scanf("%d",&a[i][j]);
	}
	N=N/3;
	NN=N+N;
	NNN=N+N+N;
	for(i=0;i<=102;++i)for(j=0;j<=102;++j)for(k=0;k<=102;++k)for(x=0;x<3;++x)dp[i][j][k][x] = INF;
	a[0][0] = 1;
	a[1][0] = 1+N;
	a[2][0] = 1+NN;
	dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;

	for(i=0;i<=cnt[0];++i){
		for(j=0;j<=cnt[1];++j){
			for(k=0;k<=cnt[2];++k){
				dp[i+1][j][k][0] = min(dp[i+1][j][k][0], 
									min(dp[i][j][k][0]+cost(a[0][i],a[0][i+1]),
									min(dp[i][j][k][1]+cost((a[1][j]+NN)%NNN,a[0][i+1]),
										dp[i][j][k][2]+cost((a[2][k]+N)%NNN,a[0][i+1]))));
				dp[i][j+1][k][1] = min(dp[i][j+1][k][1],
									min(dp[i][j][k][0]+cost((a[0][i]+N)%NNN,a[1][j+1]),
									min(dp[i][j][k][1]+cost(a[1][j],a[1][j+1]),
										dp[i][j][k][2]+cost((a[2][k]+NN)%NNN,a[1][j+1]))));
				dp[i][j][k+1][2] = min(dp[i][j][k+1][2],
									min(dp[i][j][k][0]+cost((a[0][i]+NN)%NNN,a[2][k+1]),
									min(dp[i][j][k][1]+cost((a[1][j]+N)%NNN,a[2][k+1]),
										dp[i][j][k][2]+cost(a[2][k],a[2][k+1]))));
			}
		}
	}
	int ans = INF;
	for(i=0;i<3;++i)ans = min(ans,dp[cnt[0]][cnt[1]][cnt[2]][i]);
	printf("%d\n",ans);
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
