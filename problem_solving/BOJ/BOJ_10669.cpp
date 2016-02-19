#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Cow
{
	int x, y, t;
	Cow(int _x = 0, int _y = 0, int _t = 0) : x(_x), y(_y), t(_t) {}
};

int main()
{
	int n;
	cin >> n;
	vector<Cow> cows0(n);
	vector<Cow> cows(n);
	for(int i = 0; i < n; ++i){
		int x, y;
		char t;
		cin >> x >> y >> t;
		cows0[i] = cows[i] = Cow(x, y, t == 'H' ? 1 : 0);
	}

	sort(cows0.begin(), cows0.end(), [](const Cow& c1, const Cow& c2) -> bool{
		return c1.x < c2.x;
	});
	sort(cows.begin(), cows.end(), [](const Cow& c1, const Cow& c2) -> bool{
		return c1.y < c2.y;
	});

	int ans = 1, area = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i; j < n; ++j){
			if(cows0[i].t == 0 || cows0[j].t == 0) continue;
			int lx = cows0[i].x;
			int rx = cows0[j].x;
			int dy = 0;
			int uy = 0;
			int mcnt = 0;
			int cnt = 0;
			int marea = 0;
			while(dy < n && uy < n){
				if(lx <= cows[dy].x && cows[dy].x <= rx && cows[dy].t == 1){
					int cy = cows[uy].y;
					bool ok = true;
					while(uy < n && cy == cows[uy].y){
						if(lx <= cows[uy].x && cows[uy].x <= rx){
							if(cows[uy].t == 0){
								ok = false;
								dy = uy;
								while(dy < n && cows[dy].y == cy) ++dy;
								uy = dy;
								cnt = 0;
								break;
							}else{
								++cnt;
							}
						}
						++uy;
					}
					if(!ok) continue;
					int narea = (rx - lx) * (cy - cows[dy].y);
					if(ans < cnt || ans == cnt && area > narea){
						ans = cnt;
						area = narea;
					}
				}else{
					++dy;
					uy = dy;
					cnt = 0;
				}
			}
		}
	}
	cout << ans << '\n' << area << '\n';
}