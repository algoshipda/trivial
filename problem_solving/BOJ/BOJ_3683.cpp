#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
struct Edge{
	int c,v;
	Edge* r;
};
int c,d,v,K,src,snk;
vector<pair<int,int>> A;
vector<pair<int,int>> B;
vector<vector<Edge*>> adj;
int cap[2][105][105];

Edge edges[10000005];
void add_edge(int u, int v, int c)
{
	Edge* U=&edges[K++];
	Edge* V=&edges[K++];
	U->v=v;
	V->v=u;
	U->c=c;
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
		vector<int> p(A.size()+B.size()+2,-1);
		vector<Edge*> pe(A.size()+B.size()+2);
		queue<int> q;
		p[src]=src;
		q.push(src);
		while(!q.empty() && p[snk]==-1){
			int cur=q.front();
			q.pop();
			for(auto& e: adj[cur]){
				if(e->c && p[e->v]==-1){
					q.push(e->v);
					p[e->v]=cur;
					pe[e->v]=e;
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
		scanf("%d%d%d",&c,&d,&v);
		memset(cap,0,sizeof(cap));
		A.clear();
		B.clear();
		for(int i=0;i<v;++i){
			char q,e;
			int w,r;
			scanf(" %c %d %c %d ",&q,&w,&e,&r);
			if(q=='C'){
				cap[0][w][r]++;
				A.push_back(make_pair(w,r));
			}else{
				cap[1][w][r]++;
				B.push_back(make_pair(w,r));
			}
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		A.erase(unique(A.begin(),A.end()),A.end());
		B.erase(unique(B.begin(),B.end()),B.end());
		src=A.size()+B.size();
		snk=A.size()+B.size()+1;
		adj=vector<vector<Edge*>>(A.size()+B.size()+2);
		for(int i=0;i<A.size();++i)add_edge(src,i,cap[0][A[i].first][A[i].second]);
		for(int i=0;i<B.size();++i)add_edge(A.size()+i,snk,cap[1][B[i].first][B[i].second]);
		for(int i=0;i<A.size();++i){
			for(int j=0;j<B.size();++j){
				if(A[i].first==B[j].second || A[i].second==B[j].first){
					add_edge(i,A.size()+j,INF);
				}
			}
		}
		printf("%d\n",v-flow());
	}
}
