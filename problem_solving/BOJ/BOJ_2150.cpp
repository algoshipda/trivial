#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
vector<int> scc[MAXN];
vector<int> adj[MAXN];
vector<int> rev_adj[MAXN];
int vis[MAXN];
int n, m, scnt;
stack<int> stk;

void dfs(int cur)
{
	vis[cur] = 1;
	for(auto nxt : adj[cur]){
		if(!vis[nxt]){
			dfs(nxt);
		}
	}
	stk.push(cur);
}

void dfs2(int cur)
{
	vis[cur] = 2;
	scc[scnt].push_back(cur);
	for(auto nxt : rev_adj[cur]){
		if(vis[nxt] == 1){
			dfs2(nxt);
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		rev_adj[y].push_back(x);
	}

	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			dfs(i);
		}
	}

	while(!stk.empty()){
		int cur = stk.top();
		stk.pop();
		if(vis[cur] == 1){
			dfs2(cur);
			++scnt;
		}
	}

	cout << scnt << '\n';

	for(int i = 0; i < scnt; ++i){
		sort(scc[i].begin(), scc[i].end());
	}

	sort(scc, scc + scnt);
	for(int i = 0; i < scnt; ++i){
		for(auto x : scc[i]){
			cout << x << ' ';
		}
		cout << "-1\n";
	}
}