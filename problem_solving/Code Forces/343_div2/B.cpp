#include <bits/stdc++.h>
using namespace std;

const int MN = 5005;
struct Info
{
	int t, l, r;
	Info(){};
};

Info info[MN];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		char c;
		cin >> c >> info[i].l >> info[i].r;
		if(c == 'M'){
			info[i].t = 1;
		}
	}
	int ans = 0;

	for(int i = 1; i <= 366; ++i){
		int f = 0;
		int m = 0;
		for(int j = 0; j < n; ++j){
			if(info[j].l <= i && i <= info[j].r){
				if(info[j].t){
					++m;
				}else{
					++f;
				}
			}
		}
		ans = max(ans, min(f, m));
	}
	cout << ans * 2 << '\n';
}

