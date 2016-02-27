#include <bits/stdc++.h>
using namespace std;

int adj[1005][1005];

int n,m;
int cnt;
int vis[1005];
void dfs(int cur)
{
	vis[cur]=1;
	for(int i=1;i<=n;++i){
		if(!vis[i] && adj[cur][i]){
			dfs(i);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x][y]=adj[y][x]=1;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			++cnt;
			dfs(i);
		}
	}
	printf("%d\n",cnt);
}
