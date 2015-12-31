#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int p[100005];
int n;

int dfs(int cur, int par)
{
	p[cur]=par;
	for(auto nxt:adj[cur]){
		if(par!=nxt){
			dfs(nxt,cur);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	dfs(1,0);
	for(int i=2;i<=n;++i)printf("%d\n",p[i]);
}
