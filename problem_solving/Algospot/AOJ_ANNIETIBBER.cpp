#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 1e5 + 10;
typedef long long lld;
struct Point
{
	int x, y, id;
	Point(int _x = 0, int _y = 0, int _id = 0) : x(_x), y(_y), id(_id) {}
};

int n, p, q;

//a-b, a-c
int ccw(int ax, int ay, int bx, int by, int cx, int cy)
{
	int dx1 = bx - ax;
	lld k = 1LL * (bx - ax) * (cy - ay) - 1LL * (by - ay) * (cx - ax);
	if(k > 0) return 1;
	if(k) return -1;
	return 0;
}

int st[MN * 4];
void build(int id = 1, int l = 0, int r = n - 1)
{
	if(l == r){
		st[id] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(id << 1, l, m);
	build(id << 1 | 1, m + 1, r);
	st[id] = 0;
}

void inc(int pos, int id = 1, int l = 0, int r = n - 1)
{
	if(l == r){
		st[id]++;
		return;
	}
	int m = (l + r) >> 1;
	if(pos <= m){
		inc(pos, id << 1, l, m);
	}else{
		inc(pos, id << 1 | 1, m + 1, r);
	}
	st[id] = st[id << 1] + st[id << 1 | 1];
}

int sum(int x, int y, int id = 1, int l = 0, int r = n - 1)
{
	if(y < l || r < x) return 0;
	if(x <= l && r <= y) return st[id];
	int m = (l + r) >> 1;
	return sum(x, y, id << 1, l, m) + sum(x, y, id << 1 | 1, m + 1, r);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> p >> q;
		vector<Point> points(n);
		for(int i = 0; i < n; ++i){
			cin >> points[i].x >> points[i].y;
		}
		sort(points.begin(), points.end(), [](const Point& a, const Point& b) -> bool{
			int k = ccw(p, 0, a.x, a.y, b.x, b.y);
			return k < 0;
		});

		for(int i = 0; i < n; ++i){
			points[i].id = i;
		}

		sort(points.begin(), points.end(), [](const Point& a, const Point& b) -> bool{
			int k = ccw(q, 0, a.x, a.y, b.x, b.y);
			return k < 0;
		});

		build();
		lld ans = 0;
		for(int i = 0; i < n; ++i){
			ans += sum(points[i].id, n - 1);
			inc(points[i].id);
		}
		cout << ans << '\n';
	}
}