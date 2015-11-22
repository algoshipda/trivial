#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int board[55][55];
int grp[55][55];
int vis[55][55];
int gsz[2505];
int n,m,gcnt,sz,a1,a2;

void dfs(int cx, int cy)
{
	vis[cx][cy]=1;
	grp[cx][cy]=gcnt;
	++sz;
	for(int i=0;i<4;++i){
		int nx=cx+dx[i];
		int ny=cy+dy[i];
		if(0<=nx && nx<n && 0<=ny && ny<m && !(board[cx][cy]&1<<i)){
			if(!vis[nx][ny])dfs(nx,ny);
		}
	}
}

void dfs2(int cx, int cy)
{
	vis[cx][cy]=1;
	for(int i=0;i<4;++i){
		int nx=cx+dx[i];
		int ny=cy+dy[i];
		if(0<=nx && nx<n && 0<=ny && ny<m){
			if(board[cx][cy]&1<<i){
				int cg=grp[cx][cy];
				int ng=grp[nx][ny];
				if(cg!=ng)a2=max(a2,gsz[cg]+gsz[ng]);
			}else if(!vis[nx][ny])dfs2(nx,ny);
		}
	}
}

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&board[i][j]);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(!vis[i][j]){
				sz=0;
				dfs(i,j);
				gsz[gcnt]=sz;
				++gcnt;
			}
			a1=max(a1,sz);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(!vis[i][j]){
				dfs2(i,j);
			}
		}
	}
	printf("%d\n",gcnt);
	printf("%d\n",a1);
	printf("%d\n",a2);
}
