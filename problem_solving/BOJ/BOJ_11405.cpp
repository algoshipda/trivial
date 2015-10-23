#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v,c,w;
    edge* r;
};
int n,m;
int src,snk;
vector<vector<edge*>> adj;
void add_edge(int u, int v, int w, int c)
{
    edge* U=new edge;
    edge* V=new edge;
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
    vector<int> dist(n+m+2,1e9);
    vector<int> p(n+m+2,-1);
    vector<edge*> pe(n+m+2);
    vector<int> in(n+m+2,0);
    queue<int> q;
    q.push(src);
    dist[src]=0;
    in[src]=1;
    p[src]=src;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        in[cur]=0;
        for(int i=0;i<adj[cur].size();++i){
            edge* e=adj[cur][i];
            if(e->c){
                if(dist[e->v]>dist[cur]+e->w){
                    dist[e->v]=dist[cur]+e->w;
                    p[e->v]=cur;
                    pe[e->v]=e;
                    if(!in[e->v]){
                        q.push(e->v);
                        in[e->v]=1;
                    }
                }
            }
        }
    }
    if(p[snk]==-1)return 0;
    int x=1e9;
    for(int s=snk;s!=p[s];s=p[s])x=min(x,pe[s]->c);
    for(int s=snk;s!=p[s];s=p[s]){
        pe[s]->c-=x;
        pe[s]->r->c+=x;
    }
    return dist[snk]*x;
}
int main()
{
    scanf("%d%d",&n,&m);
    src=n+m;
    snk=n+m+1;
    adj=vector<vector<edge*>>(n+m+2);
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        add_edge(src,i,0,x);
    }
    for(int i=0;i<m;++i){
        int x;
        scanf("%d",&x);
        add_edge(n+i,snk,0,x);
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            int x;
            scanf("%d",&x);
            add_edge(j,n+i,x,1e9);
        }
    }
    int ans=0;
    while(int x=spfa())ans+=x;
    printf("%d\n",ans);
}