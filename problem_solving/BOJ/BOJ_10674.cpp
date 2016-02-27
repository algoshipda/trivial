#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 105;
const int MM = 10005;
int dp[2][MN][MM];
vector<int> adj[MN], cost[2][MN];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		adj[u].push_back(v);
		cost[0][u].push_back(a);
		cost[1][u].push_back(b);
	}

	dp[0][1][0] = dp[1][1][0] = 1;
	for(int i = 1; i < n; ++i){
		for(int j = 0; j <= 10000; ++j){
			for(int k = 0; k < adj[i].size(); ++k){
				if(j + cost[0][i][k] <= 10000) dp[0][adj[i][k]][j + cost[0][i][k]] |= dp[0][i][j];
				if(j + cost[1][i][k] <= 10000) dp[1][adj[i][k]][j + cost[1][i][k]] |= dp[1][i][j];
			}
		}
	}
	for(int i = 1; i <= 10000; ++i){
		if(dp[0][n][i] && dp[1][n][i]){
			cout << i << '\n';
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
}