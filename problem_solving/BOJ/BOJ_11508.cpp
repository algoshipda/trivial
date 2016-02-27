#include <iostream>
#include <algorithm>

using namespace std;
const int MN = 1e5 + 10;
int price[MN];
long long dp[MN];

void dmin(long long &a, long long b)
{
	a = min(a, b);
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> price[i];
		dp[i] = 1e17;
	}
	sort(price + 1, price + n + 1);
	for(int i = 0; i < n; ++i){
		int sum = 0;
		int minp = 1e9;
		dmin(dp[i + 1], dp[i] + price[i + 1]);
		if(i + 3 <= n){
			dmin(dp[i + 3], dp[i] + price[i + 1] + price[i + 2] + price[i + 3] - min({price[i + 1], price[i + 2], price[i + 3]}));
		}
	}
	cout << dp[n] << '\n';
}