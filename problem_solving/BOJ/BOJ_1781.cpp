#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

const int MN = 2e5 + 10;
int n;
pair<int, int> task[MN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	set<int> nused;
	for(int i = 0; i < n; ++i){
		cin >> task[i].second >> task[i].first;
		nused.insert(- i - 1);
	}
	sort(task, task + n);
	int ans = 0;
	for(int i = n - 1; i >= 0; --i){
		auto lb = nused.lower_bound(-task[i].second);
		if(lb != nused.end()){
			ans += task[i].first;
			nused.erase(lb);
		}
	}
	cout << ans << '\n';
}