#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
	int x, y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	bool operator < (const Point& rhs) const
	{
		if(x != rhs.x) return x < rhs.x;
		return y < rhs.y;
	}

};

int ccw(Point& a, Point& b, Point& c)
{
	long long k = 1ll * (b.x - a.x) * (c.y - a.y) - 1ll * (b.y - a.y) * (c.x - a.x);
	if(k > 0) return 1;
	if(k < 0) return -1;
	return 0;
}

int main()
{
	int n;
	cin >> n;
	vector<Point> p(n);
	int mi = -1;
	for(int i = 0; i < n; ++i){
		cin >> p[i].x >> p[i].y;
		if(mi == -1 || p[i] < p[mi]){
			mi = i;
		}
	}
	swap(p[mi], p[0]);
	sort(p.begin() + 1, p.end(), [&](Point a, Point b) -> bool{
		int k = ccw(p[0], a, b);
		if(k > 0) return 1;
		if(k < 0) return 0;
		return a < b;
	});

	vector<Point> stk;
	for(auto& po : p){
		while(stk.size() >= 2 && ccw(stk[stk.size() - 2], stk.back(), po) <= 0) stk.pop_back();
		stk.push_back(po);
	}
	cout << stk.size() << '\n';
}

