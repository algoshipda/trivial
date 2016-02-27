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
using namespace std;
typedef long long lld;

int K;
struct Edge {
	int c, v;
	Edge* r;
	Edge() {};
};

int n, p, m;
int N;
int src, snk;
int shift;
int cnt[55];
int psum[55];
Edge edges[2000005];

vector<vector<Edge*> > adj;
vector<int> level;
vector<int> iter;
void add_edge(int u, int v, int c)
{
	Edge* U = &edges[K++];
	Edge* V = &edges[K++];
	U->v = v;
	V->v = u;
	U->c = c;
	V->c = 0;
	U->r = V;
	V->r = U;
	adj[u].push_back(U);
	adj[v].push_back(V);
}

void bfs()
{
	queue<int> q;
	level[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < (int)adj[cur].size(); ++i) {
			Edge* e = adj[cur][i];
			if (e->c && level[e->v] == -1) {
				level[e->v] = level[cur] + 1;
				q.push(e->v);
			}
		}
	}
}

int dfs(int cur, int f)
{
	if (cur == snk)return f;
	for (int& i = iter[cur]; i < adj[cur].size(); ++i) {
		Edge* e = adj[cur][i];
		if (e->c && level[e->v]>level[cur]) {
			int x = dfs(e->v, min(f, e->c));
			if (x) {
				e->c-=x;
				e->r->c += x;
				return x;

			}
		}
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d%d%d", &n, &p, &m);
		int sum = 0;
		K = 0;
		for (int i = 1; i <= p; ++i) {
			scanf("%d", &cnt[i]);
			sum += cnt[i];
			cnt[i] += cnt[i - 1];
		}

		N = 2 + n + n*p + sum;
		adj = vector<vector<Edge*> >(N);
		shift = n + n*p;
		src = N - 2;
		snk = N - 1;

		for (int i = 1; i <= p; ++i) {
			int x = cnt[i] - cnt[i - 1];
			for (int j = 0; j < x; ++j) {
				add_edge(shift + cnt[i - 1] + j, snk, 1);
			}
		}

		for (int i = 0; i < n; ++i)add_edge(src, i, m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < p; ++j) {
				add_edge(i, n + i*p + j, 1);
			}
		}
		for (int i = 0; i < n; ++i) {
			int l;
			scanf("%d", &l);
			for (int j = 0; j < l; ++j) {
				int x, y;
				scanf("%d%d", &x, &y);
				add_edge(n+i*p + x - 1, shift + cnt[x - 1] + y - 1,1);
			}
		}
		int f = 0;
		while (true) {
			level = vector<int>(N, -1);
			bfs();
			if (level[snk] == -1)break;
			iter = vector<int>(N);
			int x;
			while (x = dfs(src, (int)1e9)) {
				f += x;
			}
		}
		printf("Case #%d\n%d\n",tc, f == sum);
	}
}