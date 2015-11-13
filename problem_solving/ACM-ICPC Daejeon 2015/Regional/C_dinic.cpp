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
vector<int> level;
vector<int> iter;
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

void bfs()
{
    queue<int> q;
    level[src]=0;
    q.push(src);
    while(!q.empty() && level[snk]==-1){
        int cur=q.front();
        q.pop();
        for(auto e:adj[cur]){
            if(e->c && level[e->v]==-1){
                level[e->v]=level[cur]+1;
                q.push(e->v);
            }
        }
    }
}

int dfs(int u, int v, int f)
{
    if(u==v)return f;
    for(int& i=iter[u];i<adj[u].size();++i){
        Edge* e=adj[u][i];
        if(e->c && level[u]<level[e->v]){
            int x=dfs(e->v,v,min(f,e->c));
            if(x>0){
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
    int ans=0;
    while(true){
        level=vector<int>(n*m+2,-1);
        bfs();
        if(level[snk]==-1)break;
        iter=vector<int>(n*m+2,0);
        int f;
        while(f=dfs(src,snk,INF))ans+=f;        
    }
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        adj=vector<vector<Edge*>>(n*m+2);
        src=n*m;
        snk=n*m+1;
        K=0;
        int sum=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int x;
                scanf("%d",&x);
                sum+=x;
                if((i+j)%2){
                    add_edge(i*m+j,snk,x);
                }else{
                    add_edge(src,i*m+j,x);
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=i%2;j<m;j+=2){
                for(int k=0;k<4;++k){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m){
                        add_edge(i*m+j,nx*m+ny,INF);
                    }
                }
            }
        }
        printf("%d\n",sum-flow());
    }
}
