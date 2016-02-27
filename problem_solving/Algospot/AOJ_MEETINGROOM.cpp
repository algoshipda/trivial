#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

int n, vcnt, scnt;
int x[MAXN * 2],  y[MAXN * 2], scc[MAXN * 4], vis[MAXN * 4];

vector< vector<int> > adj;
vector< vector<int> > rev_adj;
stack<int> stk;

int NOT(int x)
{
	if(x > 2 * n)return x - 2 * n;
	return x + 2 * n;
}

bool is_overlap(int i, int j)
{
	if(y[i] <= x[j] || y[j] <= x[i]) return false;
	return true;
}

void read_input()
{
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> x[i] >> y[i] >> x[i + n] >> y[i + n];
	}
}

void init()
{
	adj = rev_adj = vector< vector<int> >(4 * n + 1);
	memset(scc, -1, sizeof(scc));
	++vcnt;
	scnt = 0;
}

void make_graph()
{
	for(int i = 1; i <= n; ++i){
		adj[NOT(i)].push_back(i + n);
		adj[NOT(i + n)].push_back(i);
		rev_adj[i + n].push_back(NOT(i));
		rev_adj[i].push_back(NOT(i + n));
	}
	for(int i = 1; i <= 2 * n; ++i){
		for(int j = i + 1; j <= 2 * n; ++j){
			if(is_overlap(i, j)){
				adj[i].push_back(NOT(j));
				adj[j].push_back(NOT(i));
				rev_adj[NOT(j)].push_back(i);
				rev_adj[NOT(i)].push_back(j);
			}
		}
	}
}

void dfs(int cur)
{
	vis[cur] = vcnt;
	for(auto &nxt : adj[cur]){
		if(vis[nxt] != vcnt) dfs(nxt);
	}
	stk.push(cur);
}

void dfs2(int cur)
{
	scc[cur] = scnt;
	for(auto &nxt : rev_adj[cur]){
		if(scc[nxt] == -1) dfs2(nxt);
	}
}

void solve()
{
	for(int i = 1; i <= 4 * n; ++i){
		if(vis[i] != vcnt){
			dfs(i);
		}
	}

	while(!stk.empty()){
		int cur = stk.top();
		stk.pop();
		if(scc[cur] == -1){
			++scnt;
			dfs2(cur);
		}
	}

	bool valid = true;
	for(int i = 1; i <= 2 * n; ++i){
		if(scc[i] == scc[NOT(i)]){
			valid = false;
			break;
		}
	}

	cout << (valid?"POSSIBLE":"IMPOSSIBLE") << '\n';
	if(!valid)return;
	for(int i = 1; i <= n; ++i){
		if(scc[i] < scc[NOT(i)]){
			cout << x[i + n] << ' ' << y[i + n] << '\n';
		}else{
			cout << x[i] << ' ' << y[i] << '\n';
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		read_input();
		init();
		make_graph();
		solve();
	}
}