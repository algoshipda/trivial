#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;

const int MN = 1e5 + 10;

struct Segment
{
	int t, ypos, open, id;
	Segment(int _t = 0, int _ypos = 0, int _open = 0, int _id = 0) : t(_t), ypos(_ypos), open(_open), id(_id) {}
	bool operator < (const Segment& rhs) const
	{
		if(t != rhs.t) return t < rhs.t;
		if(open != rhs.open) return open > rhs.open;
		if(open){
			return ypos < rhs.ypos;
		}
		return ypos > rhs.ypos;
	}
};


int open[MN], close[MN];

int chk[MN];
int main()
{
	int n;
	cin >> n;
	vector<Segment> segments(n * 2);
	for(int i = 0; i < n; ++i){
		int x, y, amt;
		cin >> x >> y >> amt;
		segments[i] = Segment(-x * amt, y, 0, i);
		segments[i + n] = Segment(-x * amt - amt, y, 1, i);
	}

	sort(segments.begin(), segments.end());
	set<pair<int, int>> ing;
	for(auto seg : segments){
		if(!ing.empty()){
			chk[ing.begin()->second] = 1;
		}
		if(seg.open){
			ing.insert(make_pair(seg.ypos, seg.id));
		}else{
			ing.erase(make_pair(seg.ypos, seg.id));
		}
		if(!ing.empty()){
			chk[ing.begin()->second] = 1;
		}
	}

	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += chk[i];
	}
	cout << ans << '\n';
}