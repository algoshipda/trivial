#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
int n, m;
vector<int> adj[MAXN];
int d[MAXN], ans[MAXN];


int dfs(int cur, int depth, int p)
{
	d[cur] = depth;
	int ret = depth;
	int cnt = 0;
	for(auto nxt : adj[cur]){
		if(nxt != p){
			if(!d[nxt]){
				++cnt;
				int x = dfs(nxt, depth + 1, cur);
				if(x >= depth){
					ans[cur] = 1;
				}
				ret = min(ret, x);
			}else{
				ret = min(ret, d[nxt]);
			}
		}
	}
	if(p == -1) ans[cur] = cnt >= 2;
	return ret;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 1; i <= n; ++i){
		if(!d[i]){
			dfs(i, 1, -1);
		}
	}
	cout << accumulate(ans + 1, ans + n + 1, 0) << '\n';
	for(int i = 1; i <= n; ++i){
		if(ans[i]){
			cout << i << ' ';
		}
	}
}