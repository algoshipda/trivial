#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
using namespace std;
typedef long long lld;
int n, r, s;

bool ok(const vector<int>& robot, lld x)
{
	lld first = 0;
	for (int i = 0; i < n; ++i) {
		if (robot[i] - r < first) {
			lld m = min(first - (robot[i] - r), x);
			lld c = robot[i] + m + r;
			first += max(0LL, c - first);
		}
		else {
			lld m = min((robot[i] - r) - first, x);
			if (first < s && first < robot[i] - m - r)return 0;
			first += 2 * r;
		}
	}
	return first >= s;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc) {
		scanf("%d%d%d", &n, &r, &s);
		vector<int> robot(n);
		for (int i = 0; i < n; ++i)scanf("%d", &robot[i]);
		lld l = 0;
		lld r = 1e9 + 1000;
		while (l < r) {
			lld mid = (l + r) >> 1;
			if (ok(robot,mid)) {
				r = mid;
			}else {
				l = mid + 1;
			}
		}
		printf("Case #%d\n%lld\n", tc, l <= 1e9 + 100 ? l : -1);
	}
	return 0;
}