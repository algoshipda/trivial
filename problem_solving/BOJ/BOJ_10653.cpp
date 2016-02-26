#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MN = 505;

inline int dist(const pii& a, const pii& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

pii pos[MN];
int dp[MN][MN];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> pos[i].first >> pos[i].second;
	}
	
	for(int i = 0; i < n; ++i) for(int j = 0; j <= m; ++j) dp[i][j] = 1e9;
	dp[0][0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= m; ++j){
			for(int k = i + 1; k < n; ++k){
				if(j + k - i - 1 > m) break;
				dp[k][j + k - i - 1] = min(dp[k][j + k - i - 1], dp[i][j] + dist(pos[i], pos[k]));
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i <= m; ++i) ans = min(ans, dp[n - 1][i]);
	cout << ans << '\n';
}
