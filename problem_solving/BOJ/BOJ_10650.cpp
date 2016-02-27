#include <iostream>
#include <algorithm>
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
const int MN = 1e5 + 10;
const int INF = 1e9;

struct Node
{
	int p, np, rnp, lnp;
	Node(int _p = INF, int _np = INF, int _rnp = INF, int _lnp = INF) 
		: p(_p), np(_np), rnp(_rnp), lnp(_lnp){}
};

pii pos[MN];
Node node[MN * 4];
int p[MN * 4], np[MN * 4];
int n, m;

inline int dist(const pii&a, const pii& b)
{
	return abs(a.first-b.first) + abs(a.second-b.second);
}

Node combine(const Node& a, const Node& b, int l, int r, int mid)
{
	if(mid < l) return b;
	if(r < mid + 1) return a;
	Node ret;
	int d = dist(pos[mid], pos[mid+1]);
	ret.p = a.p + b.p + d;
	ret.np = min(a.p + b.np, a.np + b.p) + d;
	if(l <= mid-1 && mid+1 <= r){
		ret.np = min(ret.np, a.rnp + b.p + dist(pos[mid-1], pos[mid+1]));
	}
	if(l <= mid && mid+2 <= r){
		ret.np = min(ret.np, a.p + b.lnp + dist(pos[mid], pos[mid+2]));
	}
	ret.rnp = a.p + b.rnp + (r == mid + 1 ? 0 : d);
	ret.lnp = a.lnp + b.p + (l == mid ? 0 : d);
	return ret;
}

void build(int id = 1, int l = 0, int r = n - 1)
{
	if(l == r){
		node[id] = Node(0, INF, 0, 0);

		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	node[id] = combine(node[id<<1], node[id<<1|1], l, r, mid);
}

void update(int idx, int id = 1, int l = 0, int r = n - 1)
{
	if(l == r) {
		return;
	}

	int mid = (l+r)>>1;
	if(idx <= mid){
		update(idx, id<<1, l, mid);
	}else{
		update(idx, id<<1|1, mid+1, r);
	}
	node[id] = combine(node[id<<1], node[id<<1|1], l, r, mid);
	return;
}

Node query(int x, int y, int id = 1, int l = 0, int r = n - 1)
{
	if(y < l || r < x) return Node(0, INF, 0, 0);
	if(x <= l && r <= y) {
		return node[id];
	}
	int mid = (l+r)>>1;
	int nx = max(x, l);
	int ny = min(y, r);
	Node ret = combine(query(nx, ny, id<<1, l, mid), 
					query(nx, ny, id<<1|1, mid+1, r), nx, ny, mid);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;
	build();
	for(int i = 0; i < m; ++i){
		char c;
		cin >> c;
		if(c == 'U'){
			int p;
			cin >> p;
			cin >> pos[p-1].first >> pos[p-1].second;
			update(p-1);
		}else{
			int l, r;
			cin >> l >> r;
			Node q = query(l-1, r-1);
			cout << min(q.p, q.np) << '\n';
		}
	}
}
