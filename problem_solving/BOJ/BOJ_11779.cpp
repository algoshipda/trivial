#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m;
int s,t;
vector<int> adj[1005];
vector<int> cost[1005];

void dijkstra()
{
	vector<int> dist(n+1,INF);
	vector<int> p(n+1,-1);
	priority_queue<pair<int,int>> q;
	dist[s]=0;
	p[s]=s;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int cur=q.top().second;
		int c=-q.top().first;
		q.pop();
		if(dist[cur]!=c)continue;
		for(int i=0;i<adj[cur].size();++i){
			int nxt=adj[cur][i];
			int nc=cost[cur][i];
			if(dist[nxt]>dist[cur]+nc){
				dist[nxt]=dist[cur]+nc;
				p[nxt]=cur;
				q.push(make_pair(-dist[nxt],nxt));
			}
		}
	}
	printf("%d\n",dist[t]);
	vector<int> path;
	while(p[t]!=t){
		path.push_back(t);
		t=p[t];
	}
	path.push_back(t);
	printf("%d\n",path.size());
	while(!path.empty()){
		printf("%d ",path.back());
		path.pop_back();
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		adj[x].push_back(y);
		cost[x].push_back(z);
	}
	scanf("%d%d",&s,&t);
	dijkstra();
}
