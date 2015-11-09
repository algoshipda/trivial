#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int vis[100005];
int cnt[100005];
int n,m;
vector<int> path;
int dfs(int cur, int p)
{
	vis[cur]=1;
	path.push_back(cur);
	for(auto nxt:adj[cur]){
		if(vis[nxt]==1 && p!=nxt){
			if(++cnt[nxt]>=2)return 1;
			for(int j=path.size()-1;path[j]!=nxt;--j){
				if(++cnt[path[j]]>=2)return 1;
			}
		}
		if(!vis[nxt]){
			if(dfs(nxt,cur))return 1;
		}
	}
	path.pop_back();
	vis[cur]=-1;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	puts(dfs(1,0)?"Not cactus":"Cactus");
}

