#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MAXN = 11;

int h, w;
lld dp[MAXN + 1][1 << MAXN];
vector<int> nxt[1 << MAXN];
vector<int> cur[2];
void dfs(int idx)
{
	if(idx == w){
		int ccur = 0;
		int nnxt = 0;
		for(int i = 0; i < w; ++i){
			ccur <<= 1;
			nnxt <<= 1;
			ccur += cur[0][i];
			nnxt += cur[1][i];
		}
		nxt[ccur].push_back(nnxt);
		return;
	}
	if(idx < w - 1){
		cur[0][idx] = cur[0][idx + 1] = 1;
		dfs(idx + 2);
		cur[0][idx] = cur[0][idx + 1] = 0;
	}
	cur[0][idx] = cur[1][idx] = 1;
	dfs(idx + 1);
	cur[0][idx] = cur[1][idx] = 0;
	dfs(idx + 1);
}

int main()
{
	while(cin >> h >> w, h != 0 && w != 0){
		for(int i = 0; i < (1 << w); ++i) nxt[i].clear();
		cur[0] = cur[1] = vector<int>(w);
		dfs(0);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < (1 << w); ++j){
				int t = ((1 << w) - 1) & ~j;
				for(int k = 0; k < nxt[t].size(); ++k){
					int nn = nxt[t][k];
					dp[i + 1][nn] += dp[i][j];
				}
			}
		}
		cout << dp[h][0] << '\n';
	}
}