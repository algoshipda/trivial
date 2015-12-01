#include <bits/stdc++.h>
using namespace std;

int vis[105];
int adj[105][105];
int n;

int dfs(int cur)
{
	vis[cur]=-1;
	for(int i=1;i<=n;++i){
		if(!adj[cur][i])continue;
		if(vis[i]==-1)return 1;
		if(!vis[i] && dfs(i)) return 1;
	}
	vis[cur]=1;
	return 0;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;++i){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;++j){
			int y;
			scanf("%d",&y);
			adj[i][y]=1;
		}
	}
	puts(dfs(1)?"CYCLE":"NO CYCLE");
}

