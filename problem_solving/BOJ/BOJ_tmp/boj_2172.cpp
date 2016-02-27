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

int N,L;
char board[22][22];
int dp[21][21][21][21][21];
int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&L);
	int i,j,k,kk,p,q,w,x,y;
	for(i=1;i<=N;++i)
		for(j=1;j<=N;++j)
			scanf(" %c",&board[i][j]);
	for(i=1;i<=N;++i)for(j=1;j<=N;++j)for(x=1;x<=N;++x)for(y=1;y<=N;++y)dp[i][j][x][y][0] = 1;
	for(i=1;i<=N;++i){
		for(j=1;j<=N;++j){
			dp[i][j][i][j][1] = 1;
			for(k=0;k<8;++k){
				int nx = i+dx[k];
				int ny = j+dy[k];
				if(nx<1 || nx>N || ny<1 || ny>N)continue;
				if(board[i][j]==board[nx][ny])dp[i][j][nx][ny][2] = dp[nx][ny][i][j][2] = 1;
			}  
		}
	}
 
	for(p=3;p<=L;++p){
		for(i=1;i<=N;++i){
			for(j=1;j<=N;++j){
				for(x=1;x<=N;++x){
					for(y=1;y<=N;++y){
						if(board[i][j]!=board[x][y])continue;
						for(k=0;k<8;++k){
							for(kk=0;kk<8;++kk){
								int nx1 = i+dx[k];
								int ny1 = j+dy[k];
								int nx2 = x+dx[kk];
								int ny2 = y+dy[kk];
								if(nx1<1 || nx1>N || ny1<1 || ny1>N)continue;
								if(nx2<1 || nx2>N || ny2<1 || ny2>N)continue;
								dp[i][j][x][y][p] += dp[nx1][ny1][nx2][ny2][p-2];
							}
						}	
					}
				}
			}
		}
	}
	int ans = 0;
	for(i=1;i<=N;++i)for(j=1;j<=N;++j)for(x=1;x<=N;++x)for(y=1;y<=N;++y) ans += dp[i][j][x][y][L];
	
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
