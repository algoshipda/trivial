#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 155;
int n, m;
int S[MN][MN], sz[MN];
vector<int> adj[MN];

void dfs(int cur, int p)
{
	sz[cur] = 1;
	
	vector<int> T[2];
	for(int i = 0; i < 2; ++i) T[i].assign(n + 1, 1e9);
	T[0][1] = 0;
	for(auto nxt : adj[cur]){
		if(nxt == p) continue;
		dfs(nxt, cur);
		for(int i = 1; i <= sz[cur]; ++i){
			T[1][i] = min(T[1][i], T[0][i] + 1);
			for(int j = 1; j <= sz[nxt]; ++j){
				T[1][i + j] = min(T[1][i + j], T[0][i] + S[nxt][j]);
			}
		}
		swap(T[0], T[1]);
		T[1].assign(n + 1, 1e9);
		sz[cur] += sz[nxt];
	}

	for(int i = 0; i <= sz[cur]; ++i){
		S[cur][i] = T[0][i];
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= n; ++j){
			S[i][j] = 1e9;
		}
	}
	dfs(1, 0);
	int ans = 1e9;
	for(int i = 1; i <= n; ++i){
		ans = min(ans, S[i][m] + (i > 1));
	}
	cout << ans << '\n';
}
