#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <iostream>
using namespace std;
typedef long long lld;

const int MOD = (int)1e9 + 7;
int n, m;
vector<vector<int> > adj;
vector<vector<int> > cycle;
int cc[105][105];
int no[105][105];
vector<int> vis;
vector<int> path;
vector<int> chk;

void dfs(int cur, int p)
{
	path.push_back(cur);
	vis[cur] = -1;
	for (int i = 0; i < (int)adj[cur].size(); ++i) {
		int nxt = adj[cur][i];
		if (vis[nxt] == -1 && nxt!=p) {
			vector<int> c;
			path.push_back(nxt);
			for (int j = (int)path.size() - 2;; --j) {
				c.push_back(cc[path[j]][path[j + 1]]);
				no[path[j]][path[j + 1]] = no[path[j+1]][path[j]] = 1;
				if (path[j] == nxt)break;
			}
			path.pop_back();
			cycle.push_back(c);
		}
		else if (!vis[nxt]) {
			dfs(nxt,cur);
		}
	}
	path.pop_back();
	vis[cur] = 1;
}

int main()
{
	int t;
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		scanf("%d%d", &n, &m);
		adj = vector<vector<int> >(n + 1);
		cycle.clear();
		memset(cc, 0, sizeof(cc));
		memset(no, 0, sizeof(no));
		for (int i = 0; i < m; ++i){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			adj[x].push_back(y);
			adj[y].push_back(x);
			cc[x][y] = cc[y][x] = z;
		}
		vis = vector<int>(n + 1);
		chk = vector<int>(n + 1);
		for (int i = 1; i <= n; ++i) {
			if (!vis[i])dfs(i,0);
		}
		for (int i = 0; i < (int)cycle.size(); ++i)sort(cycle[i].begin(), cycle[i].end());
		int l = 0;
		int r = 1000;
		while (l < r) {
			int mid = (l + r) >> 1;
			bool valid = true;
			for (int i = 1; i <= n; ++i) {
				for (int j = 0; j < (int)adj[i].size(); ++j) {
					int nxt = adj[i][j];
					if (!no[i][nxt] && cc[i][nxt] > mid) {
						valid = false;
						break;
					}
				}
				if (!valid)break;
			}
			for (int i = 0; i < (int)cycle.size() && valid; ++i) {
				if (cycle[i][(int)cycle[i].size() - 2] > mid) {
					valid = false;
					break;
				}
			}
			if (valid) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		int ans1 = 1;
		int ans2 = 1;
		for (int i = 0; i < (int)cycle.size(); ++i) {
			int k = cycle[i].back();
			int b = 1;
			if (cycle[i].back() <= l)b = cycle[i].size();
			int a = upper_bound(cycle[i].begin(), cycle[i].end(), k) - lower_bound(cycle[i].begin(), cycle[i].end(), k);
			ans1 = (lld)ans1 * a % MOD;
			ans2 = (lld)ans2 * b % MOD;
		}
		printf("Case #%d\n%d %d\n", tc, ans1, ans2);
	}
	return 0;
}