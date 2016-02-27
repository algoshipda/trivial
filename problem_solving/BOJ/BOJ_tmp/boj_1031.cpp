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
#define ff first
#define ss second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

struct Edge{
    int v,c;
    Edge* r;
    Edge(int _v=0,int _c=0):v(_v),c(_c){}
    void push(int amt){
        c-=amt;
        r->c += amt;
    }
};




Edge edges[100005];

int N,M,K,V;
int matched[52][52];
int visited[52];
int vcnt;
vector< vector<Edge* > > adj;
vector< int > level;
vector< int > iter;

void add_edge(int u, int v, int c)
{
    Edge* U = &edges[K++];
    Edge* V = &edges[K++];
    U->c = c;
    V->c = 0;
    U->v = v;
    V->v = u;
    U->r = V;
    V->r = U;
    adj[u].pb(U);
    adj[v].pb(V);
}

void bfs()
{
    queue<int> q;
    level = vector<int>(V,-1);
    q.push(0);
    level[0]=0;
    while(!q.empty() && level[1]==-1){
        int u = q.front();q.pop();
        for(int i=0;i<sz(adj[u]);++i){
            Edge* e = adj[u][i];
            if(e->c>0 && level[e->v]==-1){
                level[e->v] = level[u]+1;
                q.push(e->v);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if(v==t)return f;
    for(int& i = iter[v];i<sz(adj[v]);++i){
        Edge* e = adj[v][i];
        if(e->c>0 && level[v] < level[e->v]){
            int d = dfs(e->v, t, min(f, e->c));
            if(d>0){
                e->c -= d;
                e->r->c += d;
                return d;
            }
        }
    }
    return 0;
}
int dinic()
{
    int ans = 0;
    while(true){
        bfs();
        if(level[1]==-1) break;
        iter = vector<int>(V,0);
        int f;
         while((f=dfs(0,1,INF)>0)){
            ans += f;
        }
    }
    return ans;
}


int cycle(int a, int b, pii bound)
{
    visited[a] = vcnt;
    for(int i=1;i<=M;++i){
        if(matched[a][i])continue;
        if(mp(a,i)<=bound)continue;
        if(i==b){
            matched[a][i] = 1;
            return 1;
        }
        
        for(int j=1;j<=N;++j){
            if(visited[j] == vcnt)continue;
            if(mp(j,i)<=bound)continue;
            if(matched[j][i]){
                if(cycle(j,b,bound)){
                    matched[j][i] = 0;
                    matched[a][i] = 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);
    V=N+M+2;
    adj = vector< vector<Edge*> >(V);
    int sum1 = 0;
    int sum2 = 0;
	for(int i=0;i<N;++i){
        int x;
        scanf("%d",&x);
        add_edge(0,i+2,x);
        sum1 += x;
	}
	for(int i=0;i<M;++i){
        int x;
        scanf("%d",&x);
        add_edge(2+N+i,1,x);
        sum2 += x;
	}
	if(sum1!=sum2){
        printf("-1");
        return 0;
	}
	for(int i=2;i<2+N;++i)
        for(int j=2+N;j<2+M+N;++j)
            add_edge(i,j,1);
        
	
	if(dinic()!=sum1){
        printf("-1");
        return 0;
	}
    for(int i=2;i<2+N;++i)
        for(int j=0;j<sz(adj[i]);++j){
            Edge* e = adj[i][j];
            if(e->c==0 &&e->v>1){
                matched[i-1][e->v-N-1]=1;
            }
        }
        


    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(!matched[i][j])continue;
            ++vcnt;
            if(cycle(i,j,mp(i,j))){
                matched[i][j] = 0;
            }
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            printf("%d",matched[i][j]);
        }
        printf("\n");
    }
	fclose(stdin);
}

