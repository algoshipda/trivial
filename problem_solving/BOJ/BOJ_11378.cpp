#include <bits/stdc++.h>
using namespace std;
struct edge{
    int c,v;
    edge* r;
};
vector<edge*> adj[3005];
int iter[3005];
int dist[3005];
int snk;
void add_edge(int u, int v, int c)
{
    edge* uu=new edge;
    edge* vv=new edge;
    uu->v=v;
    vv->v=u;
    uu->c=c;
    vv->c=0;
    uu->r=vv;
    vv->r=uu;
    adj[u].push_back(uu);
    adj[v].push_back(vv);
}

int dfs(int cur, int f)
{
    if(cur==snk)return f;
    for(int& i=iter[cur];i<adj[cur].size();++i){
        edge* e=adj[cur][i];
        if(e->c && dist[cur]<dist[e->v]){
            int x=dfs(e->v,min(f,e->c));
            if(x){
                e->c-=x;
                e->r->c+=x;
                return x;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;++j){
            int y;
            scanf("%d",&y);
            add_edge(i,n+y,1);
        }
    }
    int mid=n+m+2;
    snk=n+m+1;
    add_edge(0,mid,k);
    for(int i=1;i<=n;++i){
        add_edge(0,i,1);
        add_edge(mid,i,99999);
    }
    for(int i=1;i<=m;++i){
        add_edge(n+i,snk,1);
    }
    int ans=0;
     while(true){
        memset(dist,-1,sizeof(dist));
        queue<int> q;
        dist[0]=0;
        q.push(0);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=0;i<adj[cur].size();++i){
                edge* e=adj[cur][i];
                if(e->c && dist[e->v]==-1){
                    dist[e->v]=dist[cur]+1;
                    q.push(e->v);
                }
            }
        }
        if(dist[snk]==-1)break;
        memset(iter,0,sizeof(iter));
        while(int x=dfs(0,k)){
            ans+=x;
        }
     }
    printf("%d\n",ans);
}