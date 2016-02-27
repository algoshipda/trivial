#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef pair<int, int> pii;

int n, t;
bool ok(pii pi, int p, int v)
{
	if(pi.second <= v) return false;
	return (p - pi.first) / (pi.second - v) <= t;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t;
	stack<pii> stk;
	for(int i = 0; i < n; ++i){
		int p, v;
		cin >> p >> v;
		while(!stk.empty() && ok(stk.top(), p, v)) stk.pop();
		stk.emplace(p, v);
	}
	cout << stk.size() << '\n';
}
