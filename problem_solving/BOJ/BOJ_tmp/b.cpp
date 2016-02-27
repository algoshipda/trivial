#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,m;
vector<int> adj[4005];
int know[4005][4005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		know[a][b]=1;
		know[b][a]=1;
	}
	int ans = INF;
	for(int i=1;i<=n;++i){
		for(int j=0;j<(int)adj[i].size();++j){
			for(int k=j+1;k<(int)adj[i].size();++k){
				int nxt1=adj[i][j];
				int nxt2=adj[i][k];
				if(know[nxt1][nxt2]){
					ans = min(ans, (int)adj[i].size() + (int)adj[nxt1].size() + (int)adj[nxt2].size() - 6);
				}
			}
		}
	}
	printf("%d\n",ans==INF?-1:ans);
}