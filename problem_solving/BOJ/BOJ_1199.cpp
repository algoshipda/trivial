#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

int n;
int adj[MAXN][MAXN];
vector<int> ord;

void dfs(int cur)
{
	for(int nxt = 1; nxt <= n; ++nxt){
		while(adj[cur][nxt] > 0){
			adj[cur][nxt]--;
			adj[nxt][cur]--;
			dfs(nxt);
		}
	}
	ord.push_back(cur);
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i){
		int deg = 0;
		for(int j = 1; j <= n; ++j){
			cin >> adj[i][j];
			deg += adj[i][j];
		}
		if(deg % 2){
			cout << -1;
			return 0;
		}
	}
	dfs(1);
	for(auto cur : ord){
		cout << cur << ' ';
	}
}