#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[50005];
int p[18][50005];
int depth[50005];

void dfs(int cur,int d,int parent)
{
    p[0][cur]=parent;
    depth[cur]=d;
    for(int i=0;i<adj[cur].size();++i){
        int nxt=adj[cur][i];
        if(nxt!=parent)dfs(nxt,d+1,cur);
    }
}

int f(int x, int k)
{
    for(int i=0;k;++i){
        if(k&1)x=p[i][x];
        k>>=1;
    }
    return x;
}

int lca(int x,int y)
{
    if(depth[x]<depth[y])swap(x,y);
    int d=depth[x]-depth[y];
    x=f(x,d);
    if(x==y)return x;
    int l=0;
    int r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(f(x,mid)==f(y,mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    return f(x,l);
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
    for(int i=0;i<17;++i){
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