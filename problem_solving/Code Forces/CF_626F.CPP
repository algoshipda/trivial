#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
const int MN = 205;
const int MK = 1005;
int n, k;

int a[MN];
int dp[2][MN][MK];

inline void add(int& a, int b)
{
	a += b;
	if(a >= MOD) a -= MOD;
}

inline int mult(int&a, long long b)
{
	return a * b % MOD;
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a + n);
	
	dp[0][0][0] = 1;
	for(int i = 0; i < n; ++i){
		int ci = i & 1;
		int ni = 1 - ci;
		int diff = i ? a[i] - a[i - 1] : 0;
		memset(dp[ni], 0, sizeof(dp[ni]));
		for(int g = 0; g <= i; ++g){
			for(int im = 0; im + diff * g <= k; ++im){
				int nim = im + diff * g;
				int val = dp[ci][g][im];
				if(g){
					add(dp[ni][g - 1][nim], mult(val, g));
				}
				add(dp[ni][g][nim], mult(val, g + 1));
				add(dp[ni][g + 1][nim], val);
			}
		}
	}
	int ans = 0;
	for(int im = 0; im <= k; ++im){
		add(ans, dp[n & 1][0][im]);
	}
	cout << ans << '\n';
}