#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct Edge{
	int v,c;
	Edge* r;
	Edge(){}
};
int n,m,K;
int src,snk;
Edge edges[100005];
vector<vector<Edge*>> adj;
void add_edge(int u, int v, int c)
{
	Edge* U=&edges[K++];
	Edge* V=&edges[K++];
	U->v=v;
	U->c=c;
	V->v=u;
	V->c=0;
	U->r=V;
	V->r=U;
	adj[u].push_back(U);
	adj[v].push_back(V);
}
int flow()
{
	int ret=0;
	while(true){
		vector<int> p(n*m+2,-1);
		vector<Edge*> pe(n*m+2);
		queue<int> q;
		q.push(src);
		p[src]=src;
		while(!q.empty() && p[snk]==-1){
			int cur=q.front();
			q.pop();
			for(int i=0;i<adj[cur].size();++i){
				Edge* e=adj[cur][i];
				if(e->c && p[e->v]==-1){
					p[e->v]=cur;
					pe[e->v]=e;
					q.push(e->v);
				}
			}
		}
		if(p[snk]==-1)break;
		int f=INF;
		for(int s=snk;s!=p[s];s=p[s]){
			f=min(f,pe[s]->c);
		}
		for(int s=snk;s!=p[s];s=p[s]){
			pe[s]->c-=f;
			pe[s]->r->c+=f;
		}
		ret+=f;
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		K=0;
		scanf("%d%d",&n,&m);
		adj=vector<vector<Edge*>>(n*m+2);
		src=n*m;
		snk=n*m+1;
		int sum=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				int x;
				scanf("%d",&x);
				if((i+j)%2){
					add_edge(i*m+j,snk,x);
				}else{
					add_edge(src,i*m+j,x);
				}
				sum+=x;
			}
		}
		for(int i=0;i<n;++i){
			for(int j=i%2;j<m;j+=2){
				for(int k=0;k<4;++k){
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(0<=nx && nx<n && 0<=ny && ny<m){
						add_edge(i*m+j,nx*m+ny,INF);
					}
				}
			}
		}
		printf("%d\n",sum-flow());
	}
}