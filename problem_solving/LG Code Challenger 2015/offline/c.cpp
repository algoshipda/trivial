#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m,q,w,K;
int N,M;
int src,snk;
struct Edge{
	int c,v;
	Edge* r;
};
vector<vector<Edge*>> adj;
vector<int> level;
vector<int> iter;

Edge edges[5000005];
void add_edge(int u, int v)
{
	Edge* U=&edges[K++];
	Edge* V=&edges[K++];
	U->v=v;
	V->v=u;
	U->c=1;
	V->c=0;
	U->r=V;
	V->r=U;
	adj[u].push_back(U);
	adj[v].push_back(V);
}
bool ok[405][405];

void bfs()
{
	queue<int> q;
	q.push(src);
	level[src]=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(int i=0;i<adj[cur].size();++i){
			Edge* e = adj[cur][i];
			if(e->c && level[e->v]==-1){
				level[e->v]=level[cur]+1;
				q.push(e->v);
			}
		}
	}
}
int dinic(int u, int v, int f)
{
	if(u==v)return f;
	for(int& i=iter[u];i<adj[u].size();++i){
		Edge* e = adj[u][i];
		if(e->c && level[u] < level[e->v]){
			int x = dinic(e->v, v, min(f,e->c));
			if(x){
				e->c-=x;
				e->r->c+=x;
				return x;
			}
		}
	}
	return 0;
}
int flow()
{
	int ret=0;
	while(true){
		level = vector<int>(N*M*2+2,-1);
		bfs();
		if(level[snk]==-1) break;
		iter = vector<int>(N*M*2+2,0);
		int x;
		while((x=dinic(src,snk,INF))){
			ret+=x;
		}
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		K=0;
		scanf("%d%d%d%d",&n,&m,&q,&w);
		N=n+1;
		M=m+1;
		memset(ok,0,sizeof(ok));
		adj=vector<vector<Edge*>>(N*M*2+2);
		vector<pair<int,int>> a(q);
		vector<pair<int,int>> b(q);
		src=N*M*2;
		snk=N*M*2+1;
		for(int i=0;i<q;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].first=x;
			a[i].second=y;
			add_edge(src,(x*M+y)*2);
		}
		for(int i=0;i<q;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			b[i].first=x;
			b[i].second=y;
			add_edge((x*M+y)*2+1,snk);
		}
		for(int i=0;i<w;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			ok[x][y]=1;
		}
		for(int i=0;i<=n;++i){
			for(int j=0;j<=m;++j){
				if(ok[i][j])continue;
				add_edge((i*M+j)*2,(i*M+j)*2+1);
				for(int k=0;k<4;++k){
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(0<=nx && nx<=n && 0<=ny && ny<=m && !ok[nx][ny]){
						add_edge((i*M+j)*2+1,(nx*M+ny)*2);
					}
				}
			}
		}
		printf("%d\n",flow()==q?1:-1);
	}
}