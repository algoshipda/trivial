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
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
char board[55][55];
int visited[55][55];
int depth[55][55];
vector<pii> adj[55][55];
int N,M;
int dp[55][55];
int X;
int process(int x, int y)
{
	if(x<1 || x>N || y<1 || y>M || board[x][y]=='H')return 0;

	int& ret = dp[x][y];
	if(ret)return ret;
	ret = 1;
	for(int i=0;i<sz(adj[x][y]);++i){
		int nx = adj[x][y][i].ff;
		int ny = adj[x][y][i].ss;
		ret = max(ret,1+process(nx,ny));
	}
	return ret;
}

int dfs(int x, int y)
{
	visited[x][y] = 1;
	for(int i=0;i<sz(adj[x][y]);++i){
		int nx = adj[x][y][i].ff;
		int ny = adj[x][y][i].ss;
		if(visited[nx][ny] && depth[nx][ny]==0){
			return true;
		}
		if(!visited[nx][ny] && dfs(nx,ny)){
			return true;
		}
	}
	depth[x][y] = ++X;
	return false;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int i,j,k;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;++i)scanf("%s",board[i]+1);
	for(i=1;i<=N;++i){
		for(j=1;j<=M;++j){
			if(board[i][j]=='H' || board[i][j]=='0')continue;
			for(k=0;k<4;++k){
				int nx = i+(board[i][j]-'0')*dx[k];
				int ny = j+(board[i][j]-'0')*dy[k];
				if(nx<1 || nx>N || ny<1 || ny>M)continue;
				adj[i][j].pb(mp(nx,ny));
			}
		}
	}
	if(dfs(1,1)){
		puts("-1");
		return 0;
	}
	printf("%d\n",process(1,1));
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
