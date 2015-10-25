#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[100005];
int p[19][100005];
int depth[100005];

void dfs(int cur,int d,int parent)
{
    p[0][cur]=parent;
    depth[cur]=d;
    for(int i=0;i<adj[cur].size();++i){
        int nxt=adj[cur][i];
        if(nxt!=parent)dfs(nxt,d+1,cur);
    }
}

int lca(int x,int y)
{
    if(depth[x]<depth[y])swap(x,y);
    int d=depth[x]-depth[y];
    for(int i=0;d;++i){
        if(d&1)x=p[i][x];
        d>>=1;
    }
    if(x==y)return x;
    for(int i=18;i>=0;--i){
        if(p[i][x]!=p[i][y]){
            x=p[i][x];
            y=p[i][y];
        }
    }
    return p[0][x];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1,1,0);
    for(int i=0;i<18;++i){
        for(int j=1;j<=n;++j){
            p[i+1][j]=p[i][p[i][j]];
        }
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
}