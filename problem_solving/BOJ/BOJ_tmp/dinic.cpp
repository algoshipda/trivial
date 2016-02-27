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
    
    Edge(int _v=0, int _c=0):v(_v),c(_c){}
    void init(){v=0;c=0;r=0;}
};

int N,M,K;
int wins[22];
int match[105][2];
vector< vector<Edge*> > adj;
vector<int> level;
vector<int> iter;
Edge edges[1000];

void add_edge(int u, int v, int c)
{
    Edge* uu = &edges[K++];
    Edge* vv = &edges[K++];
    uu->init();
    vv->init();
    uu->v = v;
    vv->v = u;
    uu->c = c;
    vv->c = 0;
    uu->r = vv;
    vv->r = uu;
    adj[u].pb(uu);
    adj[v].pb(vv);
}

void bfs()
{
    level = vector<int>(N+M+2,-1);
    queue<int> q;
    level[0] = 0;
    q.push(0);
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

//v 현재 t 싱크
int dfs(int v, int t, int f)
{
    if(v==t)return f;
    for(int& i=iter[v];i<sz(adj[v]);++i){
        Edge* e = adj[v][i];
        if(e->c>0 && level[v]<level[e->v]){
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
        //증가경로를 bfs로 찾는다.
        bfs();
        //증가경로 없다.
        if(level[1] == -1)break;
        //증가경로 있다 dfs로 흘려보낸다.
        iter = vector<int>(N+M+2,0);
        int f;
        while((f = dfs(0,1,INF)))
            ans += f;
    }
    return ans;
}
int ok(int totalWins)
{
    if(*max_element(wins+1,wins+N)>=totalWins)return 0;
    adj = vector< vector<Edge* > >(N+M+2);
    for(int i=0;i<M;++i){
        add_edge(0,2+i,1);
        add_edge(2+i,2+M+match[i][0],1);
        add_edge(2+i,2+M+match[i][1],1);
    }
    for(int i=0;i<N;++i){
        int maxWins = (i==0)?totalWins:totalWins-1;
        add_edge(2+M+i,1,maxWins-wins[i]);
    }
    return dinic()==M;
}
int main()
{
	//freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        K = 0;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;++i)scanf("%d",&wins[i]);
        int up = 0;
        for(int i=0;i<M;++i){
            scanf("%d%d",&match[i][0],&match[i][1]);
            if(match[i][0] == 0 || match[i][1] == 0)++up;
        }
        up+=wins[0];
        for(int i=wins[0];i<=up;++i){
            if(ok(i)){
                printf("%d\n",i);
                break;
            }
            if(i==up)puts("-1");
        }
    }
	//fclose(stdin);
}

