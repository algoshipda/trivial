#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pii;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pii> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i].first >> v[i].second;
			v[i].first = n - v[i].first;
			v[i].second = n - v[i].second;
		}

		sort(v.begin(), v.end());
		stack<int> stk;
		for(int i = 0; i < n; ++i){
			while(!stk.empty() && stk.top() < v[i].second) stk.pop();
			stk.push(v[i].second);
		}
		cout << stk.size() << '\n';
	}
}
