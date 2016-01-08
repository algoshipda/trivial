#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
int dist[1005][1005];
int h,w;
char board[1005][1005];
int main()
{
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;++i){
		scanf("%s",board[i]);
	}
	queue<pair<int,int>> q;
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			if(board[i][j]=='.')continue;
			int cnt=0;
			for(int k=0;k<8;++k){
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(0<=nx && nx<h && 0<=ny && ny<w){
					if(board[nx][ny]=='.')++cnt;
				}
			}
			if(cnt>=board[i][j]-'0'){
				q.push(make_pair(i,j));
				dist[i][j]=1;
			}
		}
	}
	while(!q.empty()){
		int cx=q.front().first;
		int cy=q.front().second;
		q.pop();
		board[cx][cy]='.';
		for(int i=0;i<8;++i){
			int nx=cx+dx[i];
			int ny=cy+dy[i];
			if(0<=nx && nx<h && 0<=ny && ny<w){
				if(board[nx][ny]!='.' && !dist[nx][ny]){
					int cnt=0;
					for(int j=0;j<8;++j){
						int xn=nx+dx[j];
						int yn=ny+dy[j];
						if(0<=xn && xn<h && 0<=yn && yn<w && board[xn][yn]=='.')++cnt;
					}
					if(cnt>=board[nx][ny]-'0'){
						dist[nx][ny]=dist[cx][cy]+1;
						q.push(make_pair(nx,ny));
					}
				}
			}
		}
	}	
	int ans=0;
	for(int i=0;i<h;++i)for(int j=0;j<w;++j)ans=max(ans,dist[i][j]);
	printf("%d\n",ans);
}
