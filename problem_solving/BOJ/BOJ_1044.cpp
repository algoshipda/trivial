#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const lld INF = 1e18;
int n;
lld x[36];
lld y[36];
lld l[300005];
lld r[300005];
int bcnt[300005];
vector<pair<lld, int>> a[20];
vector<pair<lld, int>> b[20];
int half;
int main()
{
	scanf("%d",&n);
	for(int i = n - 1; i >= 0; --i)scanf("%lld", &x[i]);
	for(int i = n - 1; i >= 0; --i)scanf("%lld", &y[i]);
	half = n >> 1;
	for(int i = 0; i < (1 << half); ++i){
		lld p = 0, q = 0;
		int cnt = 0;
		for(int j = 0; j < half; ++j){
			if(i & 1 << j){
				++cnt;
				q += y[j];
			}else{
				p += x[j];
			}
		}
		bcnt[i] = cnt;
		a[cnt].push_back(make_pair(p - q, i));
		l[i] = p - q;
		p = 0, q = 0;
		for(int j = 0; j < half; ++j){
			if(i & 1 << j){
				q += y[half + j]; 
			}else{
				p += x[half + j];
			}
		}
		b[cnt].push_back(make_pair(p - q, i));
		r[i] = p - q;
	}
	lld ans = INF;
	lld mask = (1LL << n) - 1;
	for(int i = 0; i <= half; ++i)sort(a[i].begin(), a[i].end()), sort(b[i].begin(), b[i].end());
	for(int i = 0; i < (1 << half); ++i){
		int cnt = half - bcnt[i];
		int idx = lower_bound(b[cnt].begin(), b[cnt].end(), make_pair(-l[i], 0)) - b[cnt].begin();
		if(idx < b[cnt].size()){
			lld dif = abs(l[i] + b[cnt][idx].first);
			lld nmask = i + ((lld)b[cnt][idx].second << half);
			if(dif < ans || dif == ans && nmask < mask){
				ans = dif;
				mask = nmask;
			}
		}
		if(idx){
			lld dif = abs(l[i] + b[cnt][idx - 1].first);
			lld nmask = i + ((lld)b[cnt][idx - 1].second << half);
			if(dif < ans || dif == ans && nmask < mask){
				ans = dif;
				mask = nmask;
			}
		}

		idx = lower_bound(a[cnt].begin(), a[cnt].end(), make_pair(-r[i], 0)) - a[cnt].begin();
		if(idx < a[cnt].size()){
			lld dif = abs(r[i] + a[cnt][idx].first);
			lld nmask = a[cnt][idx].second + ((lld)i << half);
			if(dif < ans || dif == ans && nmask < mask){
				ans = dif;
				mask = nmask;
			}
		}		
		if(idx){
			lld dif = abs(r[i] + a[cnt][idx - 1].first);
			lld nmask = a[cnt][idx - 1].second + ((lld)i << half);
			if(dif < ans || dif == ans && nmask < mask){
				ans = dif;
				mask = nmask;
			}
		}
	}
	for(int i = n - 1; i >= 0; --i){
		printf("%d ", (mask & 1LL << i) ? 2 : 1);
	}
	puts("");
}