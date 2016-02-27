#include <bits/stdc++.h>
using namespace std;

int tt[4] = {1, 10, 100, 1000};
int prime[10000];
int dist[10000];
int main()
{
	for(int i = 3; i < 10000; ++i){
		prime[i] = true;
		for(int j = 2; j * j <= i ; ++j){
			if(i % j == 0){
				prime[i] = false;
				break;
			}
		}
	}
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		memset(dist, -1, sizeof(dist));
		dist[a] = 0;
		queue<int> q;
		q.push(a);
		while(!q.empty() && dist[b] == -1){
			int cur = q.front();
			q.pop();
			int d = dist[cur] + 1;
			for(int i = 0; i < 4; ++i){
				for(int j = 0; j <= 9; ++j){
					if(i == 3 && j == 0) continue;
					int nxt = cur - cur % (tt[i] * 10) / tt[i] * tt[i] + j * tt[i];
					if(!prime[nxt] || dist[nxt] != -1) continue;
					dist[nxt] = d;
					q.push(nxt);
				}
			}
		}
		if(dist[b] == -1){
			cout << "Impossible" << '\n';
		}else{
			cout << dist[b] << '\n';
		}
	}
}