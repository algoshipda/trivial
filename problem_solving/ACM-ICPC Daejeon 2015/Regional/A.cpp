#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m,K;
int src,snk;
int ans;
struct Edge{
	int v,c,w;
	Edge* r;
};
Edge edges[600005];
vector<vector<Edge*>> adj;
void add_edge(int u, int v, int c, int w)
{
	Edge* U=&edges[K++];
	Edge* V=&edges[K++];
	U->v=v;
	V->v=u;
	U->c=c;
	V->c=0;
	U->w=w;
	V->w=-w;
	U->r=V;
	V->r=U;
	adj[u].push_back(U);
	adj[v].push_back(V);
}

int spfa()
{
	vector<int> dist(n*2+2,INF);
	vector<int> p(n*2+2,-1);
	vector<Edge*> pe(n*2+2);
	vector<int> in(n*2+2,0);
	queue<int> q;
	dist[src]=0;
	in[src]=1;
	q.push(src);
	p[src]=src;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		in[cur]=0;
		for(auto e:adj[cur]){
			if(e->c && dist[e->v]>dist[cur]+e->w){
				dist[e->v]=dist[cur]+e->w;
				p[e->v]=cur;
				pe[e->v]=e;
				if(!in[e->v]){
					in[e->v]=1;
					q.push(e->v);
				}
			}
		}
	}
	if(p[snk]==-1)return 0;
	for(int s=snk;s!=p[s];s=p[s]){
		pe[s]->c--;
		pe[s]->r->c++;
	}
	ans+=dist[snk];
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		K=ans=0;
		snk=n*2+1;
		adj=vector<vector<Edge*>>(n*2+2);
		vector<vector<int>> d(n+1,vector<int>(n+1,INF));
		for(int i=1;i<=n;++i)d[i][i]=0;
		for(int i=0;i<m;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			d[x][y]=d[y][x]=1;
		}
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=i;j<=n;++j){
					d[i][j]=d[j][i]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
		vector<int> a(n+1);
		vector<int> b(n+1);
		int cnt=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			cnt+=a[i];
		}
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		int blk=cnt<=n/2;
		for(int i=1;i<=n;++i){
			if(a[i]==blk)add_edge(src,i,1,0);
			if(b[i]==blk)add_edge(i+n,snk,1,0);
			for(int j=1;j<=n;++j){
				if(a[i]==blk && b[j]==blk){
					add_edge(i,j+n,1,d[i][j]);
				}
			}
		}
		while(spfa());
		printf("%d\n",ans);
	}
}
