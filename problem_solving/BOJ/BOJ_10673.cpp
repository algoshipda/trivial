#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long lld;


struct Edge
{
	int nxt, cost, cnt;
	Edge(int _nxt = 0, int _cost = 0, int _cnt = 0) : nxt(_nxt), cost(_cost), cnt(_cnt) {}
};

struct Node
{
	int id;
	pair<lld, int> c;
	Node(int _id = 0, pair<lld, int> x = make_pair(0, 0)) : id(_id), c(x) {}
	bool operator < (const Node& rhs) const
	{
		return c > rhs.c;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int src, des, n;
	cin >> src >> des >> n;
	vector<vector<pair<lld, int>>> dist(1001, vector<pair<lld, int>>(1001, make_pair(1e17, 1e9)));
	for(int i = 0; i < n; ++i){
		int cost, cnt;
		cin >> cost >> cnt;

		vector<int> num(cnt);
		for(int j = 0; j < cnt; ++j){
			cin >> num[j];
		}
		for(int j = 0; j < cnt; ++j){
			for(int k = j + 1; k < cnt; ++k){
				int u = num[j];
				int v = num[k];
				dist[u][v] = min(dist[u][v], make_pair(1ll * cost, k - j));
			}
		}
	}

	vector<vector<Edge>> adj(1001);
	for(int i = 1; i <= 1000; ++i){
		for(int j = 1; j <= 1000; ++j){
			if(dist[i][j].first < 1e17){
				adj[i].push_back(Edge(j, dist[i][j].first, dist[i][j].second));
			}
		}
	}

	vector<pair<lld, int>> dis(1001, make_pair(1e17, 1e9));
	priority_queue<Node> pq;
	dis[src] = make_pair(0, 0);
	pq.push(Node(src, dis[src]));
	while(!pq.empty()){
		Node cur = pq.top();
		pq.pop();
		if(dis[cur.id] != cur.c) continue;
		for(Edge& edge : adj[cur.id]){
			pair<lld, int> ndist = make_pair(cur.c.first + edge.cost, cur.c.second + edge.cnt);
			if(dis[edge.nxt] > ndist){
				dis[edge.nxt] = ndist;
				pq.push(Node(edge.nxt, ndist));
			}
		}
	}

	if(dis[des].first < 1e17){
		cout << dis[des].first << ' ' << dis[des].second << '\n';
	}else{
		cout << -1 << ' ' << -1 << '\n';
	}
}