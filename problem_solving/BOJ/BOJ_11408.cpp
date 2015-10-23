#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v,c,w;
    edge* r;
};

int n,m;
int src,snk;
int fans,wans;
vector<vector<edge*>> adj;

void add_edge(int u, int v, int c, int w)
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
    vector<int> in(n+m+2,0);
    vector<int> p(n+m+2,-1);
    vector<edge*> pe(n+m+2);
    queue<int> q;
    dist[src]=0;
    q.push(src);
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
    for(int s=snk;s!=p[s];s=p[s]){
        pe[s]->c--;
        pe[s]->r->c++;
    }
    fans++;
    wans+=dist[snk];
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    adj=vector<vector<edge*>>(n+m+2);
    src=n+m;
    snk=n+m+1;
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;++j){
            int vv,ww;
            scanf("%d%d",&vv,&ww);
            add_edge(i,n+vv-1,1,ww);
        }
        add_edge(src,i,1,0);
    }
    for(int i=0;i<m;++i)add_edge(n+i,snk,1,0);
    while(spfa());
    printf("%d\n%d\n",fans,wans);
}