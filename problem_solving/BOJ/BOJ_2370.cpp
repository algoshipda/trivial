#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 2e5 + 10;
int n, N;
int chk[MAXN * 4];
int lazy[MAXN * 4];

void put(int x, int y, int val, int id = 1, int l = 0, int r = N -1)
{
	if(y < l || r < x) return;
	if(x <= l && r <= y){
		lazy[id] = val;
		return;
	}
	int m = (l + r) / 2;
	if(lazy[id]){
		lazy[id + id] = lazy[id + id + 1] = lazy[id];
		lazy[id] = 0;
	}
	put(x, y, val, id + id, l, m);
	put(x, y, val, id + id + 1, m + 1, r);
}

set<int> s;

void get(int id = 1, int l = 0, int r = N - 1)
{
	if(lazy[id]){
		s.insert(lazy[id]);
		return;
	}
	if(l == r) return;
	int m = (l + r) / 2;
	get(id + id, l, m);
	get(id + id + 1, m + 1, r);
}

int main()
{
	cin >> n;
	vector<int> pos(n * 2);
	vector<pair<int,int>> query(n);
	for(int i = 0; i < n; ++i){
		cin >> pos[i] >> pos[i + n];
		query[i] = make_pair(pos[i], pos[i + n]);
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());
	N = pos.size();

	for(int i = 0; i < n; ++i){
		int l = lower_bound(pos.begin(), pos.end(), query[i].first) - pos.begin();
		int r = lower_bound(pos.begin(), pos.end(), query[i].second) - pos.begin();
		put(l, r, i + 1);
	}
	get();
	cout << s.size() << '\n';
}