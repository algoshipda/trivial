#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lld;

const int INF = 2e9 + 100;
struct P
{
	int x, y;
	P(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	bool operator < (const P& rhs) const
	{
		return x < rhs.x;
	}
};

int n, k;
vector<P> pos;

bool ok(lld m)
{
	int cnt = 1;
	int miny = INF;
	int maxy = -INF;
	for(int i = 0; i < n; ++i){
		miny = min(miny, pos[i].y);
		maxy = max(maxy, pos[i].y);
		if(1LL * maxy - miny > m){
			cnt++;
			miny = maxy = pos[i].y;
		}
	}
	return cnt <= k;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		pos = vector<P>(n);
		for(int i = 0; i < n; ++i){
			cin >> pos[i].x >> pos[i].y;
		}

		sort(pos.begin(), pos.end());
		int l = 0;
		int r = 2e9;
		while(l < r){
			lld m = (1LL * l + r) / 2;
			if(ok(m)){
				r = m;
			}else{
				l = m + 1;
			}
		}
		cout << l / 2 << '.' << l % 2 * 5 << '\n';
	}
}