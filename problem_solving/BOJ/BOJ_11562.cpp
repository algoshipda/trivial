#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m,q;
int src,snk;
int adj[255][255];
int ans[255][255];

void bfs(int s)
{
	ans[s][s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int cur=q.front();
		int c=ans[s][cur];
		q.pop();
		for(int i=1;i<=n;++i){
			if(adj[cur][i]){
				if(ans[s][i]>c){
					ans[s][i]=c;
					q.push(i);
				}
			}else if(adj[i][cur]){
				if(ans[s][i]>c+1){
					ans[s][i]=c+1;
					q.push(i);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z){
			adj[x][y]=adj[y][x]=1;
		}else{
			adj[x][y]=1;
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)ans[i][j]=INF;
	scanf("%d",&q);
	for(int i=1;i<=n;++i)bfs(i);
	for(int i=0;i<q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",ans[x][y]);
	}
}
