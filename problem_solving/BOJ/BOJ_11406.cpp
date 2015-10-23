#include <bits/stdc++.h>
using namespace std;

struct edge{
    int v,c;
    edge* r;
};
int n,m;
int src,snk;
vector<vector<edge*>> adj;
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
int main()
{
    scanf("%d%d",&n,&m);
    adj=vector<vector<edge*>>(n+m+2);
    src=n+m;
    snk=n+m+1;
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        add_edge(src,i,x);
    }
    for(int i=0;i<m;++i){
        int x;
        scanf("%d",&x);
        add_edge(n+i,snk,x);
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            int x;
            scanf("%d",&x);
            add_edge(j,n+i,x);
        }
    }
    int ans=0;
    while(true){
        vector<int> p(n+m+2,-1);
        vector<edge*> pe(n+m+2);
        queue<int> q;
        q.push(src);
        p[src]=src;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=0;i<adj[cur].size();++i){
                edge* e=adj[cur][i];
                if(e->c && p[e->v]==-1){
                    p[e->v]=cur;
                    pe[e->v]=e;
                    q.push(e->v);
                }
            }
        }
        if(p[snk]==-1)break;
        int x=1e9;
        for(int s=snk;s!=p[s];s=p[s])x=min(x,pe[s]->c);
        for(int s=snk;s!=p[s];s=p[s]){
            pe[s]->c-=x;
            pe[s]->r->c+=x;
        }
        ans+=x;
    }
    printf("%d\n",ans);
}