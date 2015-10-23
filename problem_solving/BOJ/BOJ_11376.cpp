#include <bits/stdc++.h>
using namespace std;
int am[2005];
int bm[2005];
vector<int> adj[2005];
int vis[2005];
int vcnt;
int dfs(int cur)
{
    if(vis[cur]==vcnt)return 0;
    vis[cur]=vcnt;
    for(int i=0;i<adj[cur].size();++i){
        int nxt=adj[cur][i];
        if(!bm[nxt]||(dfs(bm[nxt]))){
            bm[nxt]=cur;
            am[cur]=nxt;
            return 1;
        }
    }

    return 0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;++j){
            int y;
            scanf("%d",&y);
            adj[i].push_back(y);
            adj[i+n].push_back(y);
        }
    }
    int ans=0;
    for(int i=1;i<=(n<<1);++i){
        ++vcnt;
        ans+=dfs(i);
    }
    printf("%d\n",ans);
}