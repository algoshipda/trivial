#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct edge{
    int v,c,w;
    edge* r;
};
int to[55][55];
vector<vector<int>> adj;
int r,c;
int n,m;
int src,snk;
int w[105][105];
vector<int> visited;
vector<int> a;
vector<int> b;
int vcnt;
char board[55][55];
void make_graph(int x, int y)
{
    vector<vector<int>> dist(r,vector<int>(c,-1));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    dist[x][y]=0;
    while(!q.empty()){
        pair<int,int> f=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            int nx=f.first+dx[i];
            int ny=f.second+dy[i];
            if(0<=nx && nx<r && 0<=ny && ny<c && dist[nx][ny]==-1){
                if(board[nx][ny]!='X'){
                    int d=dist[f.first][f.second]+1;
                    dist[nx][ny]=d;
                    q.push(make_pair(nx,ny));
                    if(board[nx][ny]=='P'){
                        adj[to[x][y]].push_back(to[nx][ny]);
                        w[to[x][y]][to[nx][ny]]=d;
                    }
                }
            }
        }
    }
}

int dfs(int cur, int k)
{
    if(visited[cur]==vcnt)return 0;
    visited[cur]=vcnt;
    for(int i=0;i<adj[cur].size();++i){
        int nxt=adj[cur][i];
        if(w[cur][nxt]<=k){
            if(b[nxt]==-1 || dfs(b[nxt],k)){
                b[nxt]=cur;
                a[cur]=nxt;
                return 1;
            }
        }
    }
    return 0;
}
int ok(int k)
{
    int cnt=0;
    a=vector<int>(n,-1);
    b=vector<int>(m,-1);
    for(int i=0;i<n;++i){
        ++vcnt;
        cnt+=dfs(i,k);
    }
    return cnt==n;
}
int main()
{
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i)scanf("%s",board[i]);
    for(int i=0;i<r;++i)for(int j=0;j<c;++j){
        if(board[i][j]=='C'){
            to[i][j]=n++;
        }
        if(board[i][j]=='P'){
            to[i][j]=m++;
        }
    }
    adj=vector<vector<int>>(n+m+2);
    for(int i=0;i<r;++i)for(int j=0;j<c;++j){
        if(board[i][j]=='C'){
            make_graph(i,j);
        }
    }
    int l=0;
    int r=5000;
    visited=vector<int>(n+m);
    while(l<r){
        int mid=(l+r)>>1;
        if(ok(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d\n",ok(l)?l:-1);
}