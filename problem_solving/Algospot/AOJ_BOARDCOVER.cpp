#include <bits/stdc++.h>
using namespace std;

int n,m;
int ans;

int dir[4][3][2]={
	{{0,0},{0,1},{1,0}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,-1}},
	{{0,0},{1,0},{1,1}}
};
char board[25][25];

void put(int x, int y, int k, char c)
{
	for(int i=0;i<3;++i){
		int nx=x+dir[k][i][0];
		int ny=y+dir[k][i][1];
		board[nx][ny]=c;
	}
}
void go()
{
	int x=-1;
	int y=-1;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(board[i][j]=='.'){
				x=i;
				y=j;
				break;
			}
		}
		if(x!=-1)break;
	}
	if(x==-1){
		++ans;
		return;
	}
	for(int i=0;i<4;++i){
		bool valid=true;
		for(int j=0;j<3;++j){
			int nx=x+dir[i][j][0];
			int ny=y+dir[i][j][1];
			if(!(0<=nx && nx<n && 0<=ny && ny<m) || board[nx][ny]=='#'){
				valid=false;
				break;	
			}
		}
		if(valid){
			put(x,y,i,'#');
			go();
			put(x,y,i,'.');
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)scanf("%s",board[i]);
		int cnt=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cnt+=board[i][j]=='.';
			}
		}
		if(cnt%3){
			puts("0");
			continue;
		}
		ans=0;
		go();
		printf("%d\n",ans);
	}
}
