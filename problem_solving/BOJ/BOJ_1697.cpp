#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
int dist[MAX];
int n, k;
int main()
{
	cin >> n >> k;
	memset(dist, -1, sizeof(dist));
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while(!q.empty() && q.front() != k){
		int cur = q.front();
		q.pop();
		int d = dist[cur] + 1;
		if(cur){
			if(dist[cur - 1] == -1){
				dist[cur - 1] = d;
				q.push(cur - 1);
			}
		}
		if(cur * 2 <= 2 * k){
			if(dist[cur * 2] == -1){
				dist[cur * 2] = d;
				q.push(cur * 2);
			}
		}
		if(cur < k){
			if(dist[cur + 1] == -1){
				dist[cur + 1] = d;
				q.push(cur + 1);
			}
		}
	}
	cout << dist[k];
}