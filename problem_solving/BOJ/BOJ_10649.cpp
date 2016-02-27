#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lld;

const lld INF = 1e15;
lld dp[1<<20];
lld key[20], mugae[20], him[20];
lld sum[1<<20];
int main()
{
	int n, h;
	cin >> n >> h;
	for(int i = 0; i < n; ++i) cin >> key[i] >> mugae[i] >> him[i];
	for(int i = 0; i < (1<<n); ++i) dp[i] = -INF;
	for(int i = 0; i < n; ++i){
		dp[1<<i] = him[i];
	}

	for(int i = 0; i < (1<<n); ++i){
		for(int j = 0; j < n; ++j){
			if(i & 1<<j){
				sum[i] += key[j];
				continue;
			}
			if(dp[i] >= mugae[j]){
				dp[i | 1<<j] = max(dp[i | 1<<j], min(dp[i] - mugae[j], him[j]));
			}
		}
	}
	lld ans = -INF;
	for(int i = 0; i < (1<<n); ++i){
		if(sum[i] >= h) ans = max(ans, dp[i]);
	}
	if(ans >= 0){
		cout << ans << '\n';
	}else{
		cout << "Mark is too tall" << '\n';
	}
}

