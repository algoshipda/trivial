#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v,c,w;
    edge* r;
};

int n,p;
int src,snk;
int ans;
vector<edge*> adj[105];
int tmp[105][105];

void add_edge(int u,int v,int c, int w)
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
    vector<int> dist(n+2,1e9);
    vector<int> in(n+2,0);
    vector<int> p(n+2,1e9);
    vector<edge*> pe(n+2);
    queue<int> q;
    in[src]=1;
    q.push(src);
    dist[src]=0;
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
                        in[e->v]=1;
                        q.push(e->v);
                    }
                }
            }
        }
    }
    if(dist[snk]>0)return 0;
    int x=1e9;
    for(int s=snk;s!=p[s];s=p[s]){
        x=min(x,pe[s]->c);
    }
    for(int s=snk;s!=p[s];s=p[s]){
        pe[s]->c-=x;
        pe[s]->r->c+=x;
    }
    ans-=x*dist[snk];
    return 1;
}

int main()
{
    scanf("%d%d",&n,&p);
    src=0;
    snk=n+1;
    add_edge(src,1,p,0);
    add_edge(n,snk,p,0);
    for(int i=1;i<=n;++i){
        if(i!=n)add_edge(i,i+1,1e9,0);
        for(int j=1;j<=n-i;++j){
            scanf("%d",&tmp[i][i+j]);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i;++j){
            int x;
            scanf("%d",&x);
            add_edge(i,i+j,tmp[i][i+j],-x);
        }
    }
    while(spfa());
    printf("%d\n",ans);
}