//huynsukoh
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iostream>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

int N,M;
vector<int> adj[200005];
vector<int> req[200005];

int color[200005];
int valid = true;
int ans;
int red;
int blue;
void pdfs(int here)
{
    for(int i=0;i<(int)adj[here].size();++i){
        int r = req[here][i];
        int next = adj[here][i];
        if(color[here] > r || color[here] + 1 < r){
            valid = false;
            return;
        }
        if(color[next]!=-1 && color[here] + color[next] != r){
            valid = false;
            return;
        }
        if(color[next]!=-1)continue;
        color[next] = r - color[here];
        pdfs(next);
    }
}
void propagation()
{
    for(int i=1;i<=N;++i){
        for(int j=0;j<(int)adj[i].size();++j){
            int u = color[i];
            int v = color[adj[i][j]];
            int r = req[i][j];
            int next = adj[i][j];
            if(u+v != r && r != 1){
                color[next] = r==2?1:0;
                pdfs(next);
            }
        }
    }
}

void dfs(int here, int pre)
{
    color[here] = pre^1;
    if(pre)++red;
    else ++blue;
    for(int i=0;i<(int)adj[here].size();++i){
        int next = adj[here][i];
        if(color[next]==-1){
            dfs(next,pre^1);
        }else{
            if(color[next]==color[here]){
                valid = false;
                return;
            }
        }
    }
}

void coloring()
{
    for(int i=1;i<=N;++i){
        if(color[i]==-1){
            red = blue = 0;
            dfs(i,0);
            ans += min(red,blue);
        }
    }
}
int main()
{
    scanf("%d%d",&N,&M);
    memset(color,-1,sizeof(color));
    for(int i=0;i<M;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].pb(b);
        adj[b].pb(a);
        req[a].pb(c);
        req[b].pb(c);
    }
    
    propagation();
    for(int i=1;i<=N;++i){
        if(color[i]==1)++ans;
    }
    coloring();
    if(valid){
        printf("%d\n",ans);
    }else{
        puts("impossible");
    }
}
