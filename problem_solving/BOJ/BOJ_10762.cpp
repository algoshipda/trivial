#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bale
{
	int p, h;
	Bale(int _p = 0, int _h = 0) : p(_p), h(_h) {}
	bool operator < (const Bale& rhs) const
	{
		return p < rhs.p;
	}
};

const int MN = 1e5 + 10;
int n, first;
Bale bale[MN];
int rtol[MN], ltor[MN];

int main()
{
	cin >> n >> first;
	for(int i = 1; i <= n; ++i){
		cin >> bale[i].h >> bale[i].p;
	}
	sort(bale + 1, bale + n + 1);
	if(bale[1].p > first || bale[n].p < first){
		cout << -1 << '\n';
		return 0;
	}

	int m;
	for(m = 1; m < n; ++m){
		if(bale[m + 1].p > first) break;
	}

	int ans = 1e9;
	int bound = m; 
	for(int i =  m + 1; i < n; ++i){
		while(bound && bale[i].p - bale[bound].p > bale[bound].h){
			--bound;
		}
		if(bound == 0) break;
		ans = min(ans, max(0, bale[i].p - bale[bound].p - bale[i].h));
	}
	bound = m + 1;
	for(int i = m; i >= 1; --i){
		while(bound <= n && bale[bound].p - bale[i].p > bale[bound].h){
			++bound;
		}
		if(bound == n + 1) break;
		ans = min(ans, max(0, bale[bound].p - bale[i].p - bale[i].h));
	}
	if(ans >= 1e9){
		cout << -1 << '\n';
		return 0;
	}
	cout << ans << '\n';
}