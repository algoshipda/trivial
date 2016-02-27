#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 2e3 + 5;
int n, lc[MN], rc[MN], dp[MN][MN];

inline void dmax(int& a, int b){ a = max(a, b); }

int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> lc[i];
	for(int i = 0; i < n; ++i) cin >> rc[i];
	for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) dp[i][j] = -1e9;
	dp[0][0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			dmax(dp[i + 1][j + 1], dp[i][j]);
			dmax(dp[i + 1][j], dp[i][j]);
			if(rc[j] < lc[i]){
				dmax(dp[i][j + 1], dp[i][j] + rc[j]);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i <= n; ++i){
		ans = max({ans, dp[i][n], dp[n][i]});
	}
	cout << ans << '\n';
}