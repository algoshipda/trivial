#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MN = 1e4 + 5;
int n;
pair<int, int> task[MN];
int main()
{
	cin >> n;
	int d = 0;
	for(int i = 0; i < n; ++i){
		cin >> task[i].first >> task[i].second;
		d = max(d, task[i].second);
	}
	set<int> s;
	for(int i = 1; i <= d; ++i){
		s.insert(-i);
	}

	sort(task, task + n);
	int ans = 0;
	for(int i = n - 1; i >= 0; --i){
		auto lb = s.lower_bound(-task[i].second);
		if(lb != s.end()){
			s.erase(lb);
			ans += task[i].first;
		}
	}
	cout << ans << '\n';
}