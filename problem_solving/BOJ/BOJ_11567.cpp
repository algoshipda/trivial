#include <bits/stdc++.h>
using namespace std;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int r,c;
char board[505][505];
int r1,c1;
int r2,c2;
bool ok(int x, int y)
{
	return 1<=x && x<=r && 1<=y && y<=c;
}
void dfs(int x, int y)
{
	board[x][y]='*';
	for(int i=0;i<4;++i){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(ok(nx,ny)){
			if(board[nx][ny]=='.'){
				dfs(nx,ny);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;++i)scanf("%s",board[i]+1);
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	bool valid=false;
	if(r1==r2 && c1==c2){
		for(int i=0;i<4;++i){
			int nx=r1+dx[i];
			int ny=c1+dy[i];
			if(ok(nx,ny) && board[nx][ny]=='.'){
				valid=true;
				break;
			}
		}
	}else{
		dfs(r1,c1);
		int cnt=0;
		for(int i=0;i<4;++i){
			int nx=r2+dx[i];
			int ny=c2+dy[i];
			if(ok(nx,ny)){
				cnt+=board[nx][ny]=='*';
			}
		}
		if(board[r2][c2]=='*' && cnt>=2){
			valid=true;
		}else if(board[r2][c2]=='X' && cnt>=1){
			valid=true;
		}
	}
	puts(valid?"YES":"NO");
}
