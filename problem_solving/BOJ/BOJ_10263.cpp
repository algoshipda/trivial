#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; ++i){
		cin >> h[i];
	}
	sort(h.begin(), h.end());
	int ans = n;
	for(int i = 0; i < n; ++i){
		ans = min(ans, h[i] + n - i - 1);
	}
	cout << ans << '\n';
}