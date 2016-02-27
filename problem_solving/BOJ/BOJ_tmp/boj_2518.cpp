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
int cnt[3];
int a[3][103];
int dp[102][102][102][3];


int cost(int a, int b)
{
	return min(abs(a-b),N-(abs(a-b)));
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
	for(i=0;i<=100;++i)for(j=0;j<=100;++j)for(k=0;k<=100;++k)for(x=0;x<3;++x)dp[i][j][k][x] = INF;
	a[0][0] = 1;
	a[1][0] = 1+N/3;
	a[2][0] = a[1][0] + N/3;
	dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;

	for(i=0;i<cnt[0];++i){
		for(j=0;j<cnt[1];++j){
			for(k=0;k<cnt[2];++k){
				if(i==0 && j==0 && k==0)continue;
				dp[i+1][j][k][0] = min(dp[i+1][j][k][0], 
									min(dp[i][j][k][0]+cost(a[0][i],a[0][i+1]),
									min(dp[i][j][k][1]+cost(((a[1][i]-N/3)+N)%N,a[0][i+1]),
										dp[i][j][k][2]+cost(((a[2][i]-(N/3*2)+N)%N),a[0][i+1]))));

			}
		}
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
