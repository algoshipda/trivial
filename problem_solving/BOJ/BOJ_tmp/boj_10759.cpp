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
const int MOD = 1000000007;
int N;
char board[505][505];
int dp[2][505][505];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%s",board[i]);
	for(i=N-1;i>=0;--i)dp[(N&1)^1][i][i] = 1;
	for(k=N-2;k>=0;--k){
		int A = (k^1)&1;
		int B = k&1;
		for(i=k;i>=0;--i){
			int y = i;
			int x = k-i;
			for(j=y;j<N;++j){
				int ny = j;
				int nx = (N+N-k-2)-j;
				if(nx<x)continue;
				if(nx<0 || nx>=N || ny<0 || ny>=N)continue;
				dp[B][x][nx] = 0;
				if(board[x][y] != board[nx][ny])continue;
				if(x+1<N && nx-1>=0){
					dp[B][x][nx] += dp[A][x+1][nx-1];
					dp[B][x][nx] %= MOD;
				}
				if(nx-1>=0){
					dp[B][x][nx] += dp[A][x][nx-1];
					dp[B][x][nx] %= MOD;
				}
				if(x+1<N){
					dp[B][x][nx] += dp[A][x+1][nx];
					dp[B][x][nx] %= MOD;
				}
				if(y+1<N)
				dp[B][x][nx] += dp[A][x][nx];
				dp[B][x][nx] %= MOD;
			}
		}
	}	
	printf("%d\n",dp[0][0][N-1]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
