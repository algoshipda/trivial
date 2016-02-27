#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lld;

int n;
lld ans;
vector<vector<pair<int, int> > > adj;
vector<int> cnt;
vector<lld> psum;

void dfs(int cur, int p)
{
	cnt[cur] = 1;
	for(int i = 0; i < adj[cur].size(); ++i){
		pair<int, int> nxt = adj[cur][i];
		if(nxt.first != p){
			dfs(nxt.first, cur);
			cnt[cur] += cnt[nxt.first];
			psum[cur] += psum[nxt.first] + cnt[nxt.first] * nxt.second;
		}
	}
}

void dfs2(int cur, lld s, int p)
{
	ans = min(ans, s);
	for(int i = 0; i < adj[cur].size(); ++i){
		pair<int, int> nxt = adj[cur][i];
		if(nxt.first != p){
			dfs2(nxt.first, s + (n - 2 * cnt[nxt.first]) * nxt.second, cur);
		}
	}
}

int main()
{
	while(cin >> n, n){
		ans = 1e17;
		adj = vector< vector< pair<int, int> > >(n);
		cnt = vector<int>(n);
		psum = vector<lld>(n);
		for(int i = 0; i < n - 1; ++i){
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		dfs(0, -1);
		dfs2(0, psum[0], -1);
		cout << ans << '\n';
	}
}