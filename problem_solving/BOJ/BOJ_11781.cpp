#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const lld INF = 1e15;
int n,m,s,e;
vector<int> adj[5005];
vector<int> cost[5005];
vector<bool> jam[5005];

void dijkstra()
{
	vector<lld> dist(n+1,INF);
	dist[1]=0;
	priority_queue<pair<lld,int>> pq;
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		int cur=pq.top().second;
		lld c=-pq.top().first;
		pq.pop();
		if(dist[cur]!=c)continue;
		for(int i=0;i<adj[cur].size();++i){
			int nxt=adj[cur][i];
			int nc=cost[cur][i];
			int f=jam[cur][i];
			if(!f && dist[nxt]>dist[cur]+nc){
				dist[nxt]=dist[cur]+nc;
				pq.push(make_pair(-dist[nxt],nxt));
			}
			if(f){
				lld x=0;
				lld y=0;
				if(s<=dist[cur] && dist[cur]<=e){
					x=min(e-dist[cur],(lld)nc*2);
				}else if(dist[cur]<=s && s<=dist[cur]+nc){
					x=min((lld)e-s,(dist[cur]+nc-s)*2);
				}
				y=nc-x/2;
				if(dist[nxt]>dist[cur]+x+y){
					dist[nxt]=dist[cur]+x+y;
					pq.push(make_pair(-dist[nxt],nxt));
				}
			}
		}
	}
	lld ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,dist[i]);
	printf("%lld",ans/2);
	if(ans%2)printf(".5");
	puts("");
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&e);
	s<<=1;
	e<<=1;
	for(int i=0;i<m;++i){
		int x,y,z,a,b;
		scanf("%d%d%d%d%d",&x,&y,&z,&a,&b);
		adj[x].push_back(y);
		adj[y].push_back(x);
		cost[x].push_back(z<<1);
		cost[y].push_back(z<<1);
		jam[x].push_back(a);
		jam[y].push_back(b);
	}
	dijkstra();
}
