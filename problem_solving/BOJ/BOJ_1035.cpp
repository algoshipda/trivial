#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int vcnt;
int vis[6][6];
map<int, int> dist;
char board[6][6];

void dfs(int cx, int cy)
{
	vis[cx][cy] = vcnt;
	for(int i = 0; i < 4; ++i){
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if(0 <= nx && nx < 5 && 0 <= ny && ny < 5 && vis[nx][ny] != vcnt && board[nx][ny] == '*'){
			dfs(nx, ny);
		}
	}
}

int chk()
{
	int cnt = 0;
	++vcnt;
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			if(vis[i][j] != vcnt && board[i][j] == '*') {
				++cnt;
				dfs(i, j);
			}
		}
	}
	return cnt == 1;
}

int get()
{
	int ret = 0;
	for(int i = 0; i < 5; ++i){
		for(int j = 0; j < 5; ++j){
			ret += ((board[i][j] == '*') << ((i * 5) + j));
		}
	}
	return ret;
}

void set_board(int cur)
{
	for(int i = 0; i < 5; ++i){
		for(int j = 0 ; j < 5; ++j){
			board[i][j] = (cur & (1 << ((i * 5) + j))) ? '*' : '.';
		}
	}
}

int bswap(int cur, int x1, int y1, int x2, int y2)
{
	int a = (cur & (1 << ((x1 * 5) + y1))) >> ((x1 * 5) + y1);
	int b = (cur & (1 << ((x2 * 5) + y2))) >> ((x2 * 5) + y2);

	int ret = cur & ~(1 << ((x1 * 5) + y1));
	ret &= ~(1 << ((x2 * 5) + y2));
	ret |= (b << ((x1 * 5) + y1));
	ret |= (a << ((x2 * 5) + y2));
	return ret; 
}

int main()
{
	for(int i = 0; i < 5; ++i)
		cin >> board[i];

	int start = get();
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		set_board(cur);
		if(chk()){
			cout << dist[cur];
			return 0;
		}
		int d = dist[cur] + 1;
		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 5; ++j){
				if(board[i][j] == '.') continue;
				for(int k = 0; k < 4; ++k){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(0 <= nx && nx < 5 && 0 <= ny && ny < 5){
						int nxt = bswap(cur, i, j, nx, ny);
						if(dist.count(nxt) == 0){
							dist[nxt] = d;
							q.push(nxt);
						}
					}
				}
			}
		}
	}
}