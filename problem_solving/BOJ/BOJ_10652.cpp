#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
int b, e, p, n, m;
vector<vector<int>> adj;

vector<int> dijkstra(int src, int d)
{
	vector<int> dist(n + 1, 1e9);
	priority_queue<pii> pq;
	dist[src] = 0;
	pq.emplace(0, src);
	while(!pq.empty()){
		int cur = pq.top().second;
		int c = -pq.top().first;
		pq.pop();
		if(c != dist[cur]) continue;
		for(auto nxt:adj[cur]){
			int nd = c + d;
			if(nd < dist[nxt]){
				dist[nxt] = nd;
				pq.emplace(-nd, nxt);
			}
		}
	}
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> b >> e >> p >> n >> m;
	adj.assign(n + 1, vector<int>());
	for(int i = 0; i  < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> dist1 = dijkstra(1, b);
	vector<int> dist2 = dijkstra(2, e);
	vector<int> dist3 = dijkstra(n, p);
	int ans = 1e9;
	for(int i = 1; i <= n; ++i){
		ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
	}
	cout << ans << '\n';
}
