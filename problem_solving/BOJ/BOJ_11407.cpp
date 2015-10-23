#include <bits/stdc++.h>
using namespace std;
struct edge{
    int v,c,w;
    edge* r;
};
int n,m;
int src,snk;
int c[205][205];
int w[205][205];
int ans,fans;
int spfa()
{
    vector<int> dist(n+m+2,1e9);
    vector<int> p(n+m+2,-1);
    vector<int> in(n+m+2,0);
    queue<int> q;
    q.push(src);
    in[src]=1;
    p[src]=src;
    dist[src]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        in[cur]=0;
        for(int i=0;i<n+m+2;++i){
            if(c[cur][i]){
                if(dist[i]>dist[cur]+w[cur][i]){
                    dist[i]=dist[cur]+w[cur][i];
                    p[i]=cur;
                    if(!in[i]){
                        q.push(i);
                        in[i]=1;
                    }
                }
            }
        }
    }
    if(p[snk]==-1)return 0;
    int x=1e9;
    for(int s=snk;s!=p[s];s=p[s])x=min(x,c[p[s]][s]);
    for(int s=snk;s!=p[s];s=p[s]){
        c[p[s]][s]-=x;
        c[s][p[s]]+=x;
    }
    fans+=x;
    ans+=dist[snk]*x;
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    src=n+m;
    snk=n+m+1;
    for(int i=0;i<n;++i)scanf("%d",&c[src][i]);
    for(int i=0;i<m;++i)scanf("%d",&c[n+i][snk]);
    for(int i=0;i<m;++i)for(int j=0;j<n;++j)scanf("%d",&c[j][n+i]);
    for(int i=0;i<m;++i)for(int j=0;j<n;++j){
        scanf("%d",&w[j][n+i]);
        w[n+i][j]=-w[j][n+i];
    }
    while(spfa());
    printf("%d\n%d\n",fans,ans);
}