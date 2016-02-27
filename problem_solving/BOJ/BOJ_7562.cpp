#include <bits/stdc++.h>
using namespace std;

const int MAXL = 305;
int dist[MAXL][MAXL];
int main()
{
	int t;
	cin >> t;
	while(t--){
		int l, x1, y1, x2, y2;
		cin >> l >> x1 >> y1 >> x2 >> y2;
		memset(dist, -1, sizeof(dist));
		dist[x1][y1] = 0;
		queue<pair<int,int>> q;
		q.push(make_pair(x1, y1));
		while(!q.empty() && !(q.front().first == x2 && q.front().second == y2)){
			pair<int, int> cur = q.front();
			q.pop();
			int d = dist[cur.first][cur.second] + 1;
			for(int i = -2; i <= 2; ++i){
				if(!i) continue;
				for(int j = -2 ; j <= 2; ++j){
					if(abs(i) == abs(j) || !j) continue;
					int nx = cur.first + i;
					int ny = cur.second + j;
					if(0 <= nx && nx < l && 0 <= ny && ny < l && dist[nx][ny] == -1){
						dist[nx][ny] = d;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		cout << dist[x2][y2] << '\n';
	}
}