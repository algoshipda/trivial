#include <stdio.h>
#include <string.h>
const int INF=1e9;
int dist[1005];
int adj[1005][1005];
int cost[1005][1005];
int acnt[1005];
int tree[4005];
int first;
int chk[1005];

void build(int n)
{
    for(first=1;first<n;first<<=1);
}
void update(int pos, int val)
{
    pos+=first;
    tree[pos]=val;
    while(pos>>1){
        if(dist[tree[pos]]>dist[tree[pos^1]]){
            tree[pos>>1]=tree[pos^1];
        }else{
            tree[pos>>1]=tree[pos];
        }
        pos>>=1;
    }
}
int min()
{
    int ret=tree[1];
    if(ret)update(ret,0);
    return ret;
}
int main()
{
    setbuf(stdout, NULL);
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(chk+1,0,sizeof(int)*n);
        memset(acnt+1,0,sizeof(int)*n);
        for(int i=0;i<m;++i){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            adj[x][acnt[x]]=y;
            cost[x][acnt[x]]=z;
            adj[y][acnt[y]]=x;
            cost[y][acnt[y]]=z;
            ++acnt[x];
            ++acnt[y];
        }
        int ans=0;
        for(int iter=1;iter<=n;++iter){
            for(int i=0;i<=n;++i)dist[i]=INF;
            build(n+1);
            dist[iter]=0;
            update(iter,iter);
            while(1){
                int cur=min();
                if(!cur)break;
                for(int i=0;i<acnt[cur];++i){
                    int nxt=adj[cur][i];
                    int c=cost[cur][i];
                    if(dist[nxt]>dist[cur]+c){
                        dist[nxt]=dist[cur]+c;
                        update(nxt,nxt);
                    }
                }
            }
            for(int cur=1;cur<=n;++cur){
                for(int i=0;i<acnt[cur];++i){
                    int nxt=adj[cur][i];
                    int c=cost[cur][i];
                    if(cur!=iter && nxt!=iter){
                        if(dist[nxt]+c==dist[cur] && !chk[nxt]){
                            chk[nxt]=1;
                            ans++;
                        }
                    }
                }
            }
        }
        printf("Case #%d\n",tc);
        printf("%d ",n-ans);
        for(int i=1;i<=n;++i)if(!chk[i])printf("%d ",i);
        puts("");
    }
}