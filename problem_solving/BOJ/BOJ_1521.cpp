#include <bits/stdc++.h>
using namespace std;

int n, target;
map<int,double> dp;
int get(int state, int pos)
{
	return (state & (7 << (pos * 3))) >> (pos * 3);
}

int bswap(int state, int pos1, int pos2)
{
	int val1 = get(state, pos1);
	int val2 = get(state, pos2);
	int ret = state;
	ret &= ~(7 << (pos1 * 3) | 7 << (pos2 * 3));
	ret |= val1 << (pos2 * 3) | val2 << (pos1 * 3);
	return ret;
}

double rec(int state)
{
	if(state == target)return 0.0;
	if(dp.count(state)){
		return dp[state];
	}

	double ret = 0.0;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			if(get(state, i) > get(state, j)){
				ret += 1.0 + rec(bswap(state, i, j));
				++cnt;
			}
		}
	}
	ret /= cnt;
	dp[state] = ret;
	return ret;
}

int main()
{
	cin >> n;
	int state = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		--x;
		state += (x << (i * 3));
		target += (i << (i * 3));
	}
	cout << fixed;
	cout << setprecision(10);
	cout << rec(state) << '\n';
}
