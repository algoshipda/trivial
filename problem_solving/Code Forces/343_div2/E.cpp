#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MN = 1e5 + 10;
const int M = 18;
int n, m;
vector<int> adj[MN];
vector<int> child[MN];
vector<int> st[MN];
int s[MN], t[MN], dep[MN], sz[MN], p[M][MN];
lld alldep[MN], subdep[MN];
int curTime;

void dfs1(int cur, int par)
{
	p[0][cur] = par;
	for(auto nxt : adj[cur]){
		if(nxt == par) continue;
		child[cur].emplace_back(nxt);
		dfs1(nxt, cur);
	}
}

void dfs2(int cur, int depth)
{
	s[cur] = ++curTime;
	dep[cur] = depth;
	alldep[cur] = depth;
	sz[cur] = 1;
	for(auto nxt : child[cur]){
		dfs2(nxt, depth + 1);
		st[cur].emplace_back(t[nxt]);
		sz[cur] += sz[nxt];
		alldep[cur] += alldep[nxt];
	}
	t[cur] = ++curTime;
}

void dfs3(int cur)
{
	for(auto nxt : child[cur]){
		alldep[nxt] = alldep[cur] + n - 2 * sz[nxt];
		dfs3(nxt);
		subdep[cur] += subdep[nxt] + sz[nxt];
	}
}

bool isSubtree(int u, int v)
{
	return s[v] < s[u] && t[u] < t[v]; 
}


int LCA(int u, int v)
{

	if(dep[u] < dep[v]) swap(u, v);
	int d = dep[u] - dep[v];
	for(int i = 0; i < M; ++i){
		if(d & 1 << i) u = p[i][u];
	}

	if(u == v) return u;

	for(int i = M - 1; i >= 0; --i){
		if(p[i][u] != p[i][v]){
			u = p[i][u];
			v = p[i][v];
		}
	}
	return p[0][u];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	dfs3(1);

	for(int i = 0; i < M - 1; ++i){
		for(int j = 1; j <= n; ++j){
			p[i + 1][j] = p[i][p[i][j]];
		}
	}

	cout << fixed;
	cout << setprecision(10);

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		int lca = LCA(u, v);
		int dist = dep[u] + dep[v] - 2 * dep[lca];
		int usz = sz[u];
		int vsz = sz[v];
		lld udep = subdep[u];
		lld vdep = subdep[v];
		if(isSubtree(u, v)){
			int idx = lower_bound(st[v].begin(), st[v].end(), s[u]) - st[v].begin();
			vsz = n - sz[child[v][idx]];
			vdep = alldep[v] - (subdep[child[v][idx]] + sz[child[v][idx]]);
		}
		if(isSubtree(v, u)){
			int idx = lower_bound(st[u].begin(), st[u].end(), s[v]) - st[u].begin();
			usz = n - sz[child[u][idx]];
			udep = alldep[u] - (subdep[child[u][idx]] + sz[child[u][idx]]);
		}
		double ans = (double)vdep / vsz + (double)udep / usz + dist + 1.0;
		cout << ans << '\n';
	}
}
