#include <bits/stdc++.h>
using namespace std;

int n, k;
int main()
{
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	vector<int> target = v;
	sort(target.begin(), target.end());
	map<vector<int>, int> dist;
	dist[v] = 0;
	queue<vector<int>> q;
	q.push(v);
	while(!q.empty()){
		vector<int> cur = q.front();
		q.pop();
		int d = dist[cur];
		for(int i = 0; i <= n - k; ++i){
			reverse(cur.begin() + i, cur.begin() + i + k);
			if(dist.count(cur) == 0){
				dist[cur] = d + 1;
				q.push(cur);
			}
			reverse(cur.begin() + i, cur.begin() + i + k);
		}
	} 
	cout << (dist.count(target) ? dist[target] : -1); 
}