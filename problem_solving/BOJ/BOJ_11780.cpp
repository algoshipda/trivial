#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int n,m;
int adj[105][105];
int via[105][105];

void rec(vector<int> &v, int x, int y)
{
	if(!via[x][y]){
		v.push_back(x);
		v.push_back(y);
		return;
	}
	rec(v,x,via[x][y]);
	v.pop_back();
	rec(v,via[x][y],y);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)adj[i][j]=INF;
	for(int i=1;i<=n;++i)adj[i][i]=0;
	for(int i=0;i<m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		adj[x][y]=min(adj[x][y],z);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(adj[i][j]>adj[i][k]+adj[k][j]){
					via[i][j]=k;
					adj[i][j]=adj[i][k]+adj[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			printf("%d ",adj[i][j]==INF?0:adj[i][j]);
		}
		puts("");
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(adj[i][j]==INF || adj[i][j]==0){
				puts("0");
				continue;
			}
			vector<int> path;
			rec(path,i,j);
			printf("%d ",path.size());
			for(auto x:path){
				printf("%d ",x);
			}
			puts("");
		}
	}
}
