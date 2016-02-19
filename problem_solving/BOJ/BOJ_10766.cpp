#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bale
{
	int h, p;
	Bale(int _h = 0, int _p = 0) : h(_h), p(_p) {}
	bool operator < (const Bale& rhs) const
	{
		return p < rhs.p;
	}
};

const int MN = 4e5 + 10;
const int INF = 1e9 + 10;
Bale bale[MN];
bool chk[MN];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> bale[i].h >> bale[i].p;
	}	
	sort(bale + 1, bale + n + 1);

	bale[0].h = bale[n + 1].h = INF;
	for(int i = 1; i < n; ++i){
		int l = i;
		int r = i + 1;
		while(true){
			bool changed = false;
			if(l != 0 && bale[r].p - bale[l].p > bale[l].h){
				--l;
				changed = true;
			}
			if(r != n + 1 && bale[r].p - bale[l].p > bale[r].h){
				++r;
				changed = true;
			}
			if(!changed) break;
		}
		if(l != 0 && r != n + 1){
			++l;
			while(l <= r){
				chk[l++] = true;
			}
		}	
	}
	int ans = 0;
	for(int i = 2; i <= n; ++i){
		if(chk[i]){
			ans += bale[i].p - bale[i - 1].p;
		}
	}
	cout << ans << '\n';
}