#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long lld;

const lld INF = 1e17;
const int MN = 1e3 + 10;

struct Grass{
	int val, id;
	Grass(int _val = 0, int _id = 0) : val(_val), id(_id) {}
	bool operator < (const Grass& rhs) const
	{
		if(val != rhs.val) return val < rhs.val;
		return id < rhs.id;
	}
};

int n, e, dist[MN][MN];
Grass grass[MN];
lld dp[MN];
vector<int> adj[MN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> e;
	for(int i = 1; i <= n; ++i){
		int d;
		cin >> grass[i].val >> d;
		grass[i].id = i;
		for(int j = 0; j < d; ++j){
			int nxt;
			cin >> nxt;
			adj[i].push_back(nxt);
		}
	}

	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) dist[i][j] = -1e9;
	for(int i = 1; i <= n; ++i){
		dist[i][i] = 0;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(auto nxt : adj[cur]){
				if(dist[i][nxt] == -1e9){
					dist[i][nxt] = dist[i][cur] + 1;
					q.push(nxt);
				}
			}
		}
	}

	sort(grass + 1, grass + n + 1);
	for(int i = 1; i <= n; ++i) dp[i] = -INF;
	for(int i = 0; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(grass[i].val < grass[j].val){
				if(dist[grass[i].id][grass[j].id] != -1e9) dp[j] = max(dp[j], dp[i] + grass[j].val - 1ll * e * dist[grass[i].id][grass[j].id]);
			}
		}
	}

	lld ans = 0;
	for(int i = 1; i <= n; ++i) ans = max(ans, dp[i]);
	cout << ans << '\n';
}