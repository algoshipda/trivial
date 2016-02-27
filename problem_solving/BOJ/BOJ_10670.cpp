#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MN = 20;
const int MS = 1005;

int N, L, D[MN];
vector<int> show[MN];
int prec[MN][MS][MN];
pair<int, int> dp[1 << MN];

int main()
{
	cin >> N >> L;
	for(int i = 0; i < N; ++i){
		int cnt;
		cin >> D[i] >> cnt;
		show[i].assign(cnt, 0);
		for(int j = 0; j < cnt; ++j){
			cin >> show[i][j];
		}
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(i == j) continue;
			for(int k = 0; k < show[i].size(); ++k){
				int v = show[i][k] + D[i];
				int idx = lower_bound(show[j].begin(), show[j].end(), v) - show[j].begin();
				if(idx < show[j].size() && show[j][idx] == v){
					prec[i][k][j] = idx;
				}else if(idx > 0 && show[j][idx - 1] <= v && v <= show[j][idx - 1] + D[j]){
					prec[i][k][j] = idx - 1;
				}
			}
		}
	}

	for(int i = 0; i < (1 << N); ++i){
		dp[i] = {-1, -1};
	}

	for(int i = 0; i < (1 << N); ++i){
		for(int j = 0; j < N; ++j){
			if(i & 1 << j) continue;
			int nxt = i | 1 << j;
			if(dp[i].first == -1){
				if(show[j][0] == 0){
					if(dp[nxt].first == -1 || show[dp[nxt].first][dp[nxt].second] + D[dp[nxt].first] <= show[j][0] + D[j]){
						dp[nxt] = {j, 0};
					}
				}

			}else{
				int cur = prec[dp[i].first][dp[i].second][j]; 
				if(dp[nxt].first == -1 || show[dp[nxt].first][dp[nxt].second] + D[dp[nxt].first] <= show[j][cur] + D[j]){
					dp[nxt] = {j, cur};
				}
			}
		}
	}

	int ans = 30;
	for(int i = 0; i < (1 << N); ++i){
		if(dp[i].first == -1) continue;
		int val = show[dp[i].first][dp[i].second] + D[dp[i].first];
		if(val >= L) ans = min(ans, __builtin_popcount(i));
	}
	cout << (ans > N ? -1 : ans) << '\n';
}