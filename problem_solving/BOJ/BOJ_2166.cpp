#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

long long f(pii& a, pii& b)
{
	return 1ll * a.first * b.second - 1ll * a.second * b.first;
}
int main()
{
	int n;
	scanf("%d", &n);
	vector<pii> p(n);
	for(int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += f(p[i], p[(i + 1) % n]);
	}
	ans = abs(ans);
	printf("%lld.%lld\n", ans / 2, ans % 2 * 5);
}
