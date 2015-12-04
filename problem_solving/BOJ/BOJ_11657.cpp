#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m;
vector<int> adj[505];
vector<int> cost[505];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		adj[x].push_back(y);
		cost[x].push_back(z);
	}
	vector<int> dist(n+1,INF);
	dist[1]=0;
	for(int i=0;i<n-1;++i){
		for(int j=1;j<=n;++j){
			for(int k=0;k<adj[j].size();++k){
				dist[adj[j][k]]=min(dist[adj[j][k]],dist[j]+cost[j][k]);
			}
		}
	}
	bool valid=true;
	for(int i=1;i<=n;++i){
		for(int j=0;j<adj[i].size();++j){
			if(dist[adj[i][j]]>dist[i]+cost[i][j]){
				valid=false;
			}
		}
	}
	if(!valid){
		puts("-1");
		return 0;
	}
	for(int i=2;i<=n;++i){
		if(dist[i]+(int)1e8>=INF)puts("-1");
		else printf("%d\n",dist[i]);
	}
}
