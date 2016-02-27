#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MN = 1e5 + 5;
const int MOD = 20150523;

int dp[MN][3][2][2];
string a, b;

int rec(int len, int mod, int clap, int less)
{
	if(len == b.size()){
		if(mod == 0 || clap) return 1;
		return 0;
	}
	int& ret = dp[len][mod][clap][less];
	if(ret != -1) return ret;
	int k = b[len] - '0';
	ret = 0;
	for(int i = 0; i <= 9; ++i){
		if(less || (!less && i <= k)){
			int nmod = (mod + i) % 3;
			int nclap = clap || (i - 1) % 3 == 2;
			int nless = less || i < k;
			ret += rec(len + 1, nmod, nclap, nless);
		}
		ret %= MOD;
	}
	return ret;
}

int main()
{
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	int fb = rec(0, 0, 0, 0);
	b = a;
	memset(dp, -1, sizeof(dp));
	int fa = rec(0, 0, 0, 0);
	int chk = 0;
	int mod = 0;
	for(int i = 0; i < a.size(); ++i){
		int k = a[i] - '0';
		if((k-1) % 3 == 2){
			chk = 1;
			break;
		}
		mod = (mod + k) % 3;
	}
	if(chk || mod == 0) fa--;
	cout << (fb - fa + MOD) % MOD << '\n'; 
}