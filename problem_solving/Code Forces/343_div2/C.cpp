#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MOD = 1e9 + 7;
const int MN = 2005;
int n, m;
int D[MN][MN];

void add(int& a, int b)
{
	a += b;
	if(a >= MOD) a -= MOD;
}

int solve(int open, int len)
{
	if(open > 2000) return 0;
	if(len == 0){
		if(open == 0){
			return 1;
		}else{
			return 0;
		}
	}
	if(open < 0) return 0;
	int& ret = D[open][len];
	if(ret != -1) return ret;
	ret = 0;
	add(ret, solve(open - 1, len - 1));
	add(ret, solve(open + 1, len - 1));
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	string s;
	cin >> s;
	if(n % 2){
		cout << 0 << '\n';
		return 0;
	}
	int r = 0;
	int cnt = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '(') ++cnt;
		else --cnt;
		r = max(r, -cnt);
	}
	memset(D, -1, sizeof(D));
	int ans = 0;
	for(int i = r; i <= n - m; ++i){
		for(int j = 0; j <= n - m; ++j){
			add(ans, (lld)solve(i, j) * solve(i + cnt, n - m - j) % MOD);
		}
	}
	cout << ans << '\n';
}
