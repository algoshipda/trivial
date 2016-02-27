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

#define pb(a) push_back((a))
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
    int v;//도착지
    int c;//용량
    int f;//플로우
    int r;//반대방향 간선 포인터
    //Edge* r
    Edge(int _v, int _c, int _f, int _r):v(_v),c(_c),f(_f),r(_r){}
    int rc() const { return c-f; }//residualCapacity;    
};

void add_edge(vector< vector<Edge> >& g, int u, int v, int c)
{
    g[u].pb(Edge(v,c,0,g[v].size()));
    g[v].pb(Edge(u,0,0,g[u].size()-1));
}

void push(vector< vector<Edge> >& g, int u, int idx, int amt)
{
    Edge& e = g[u][idx];
    e.f += amt;
    g[e.v][e.r].f -= amt;
}





int N,M;
vector<int> wins;
vector< vector<int> > match;





int networkFlow(int s, int t, vector< vector<Edge> >& g)
{
    int ans = 0;
    while(true){
        //증가경로를 찾는다.
        pii undef = mp(-1,-1);
        vector<pii> parent(N+M+2, undef);
        queue<int> q;
        q.push(s);
        parent[s] = mp(s,0);
        while(!q.empty() && parent[t] == undef){
            int u = q.front();q.pop();
            for(int i=0;i<(int)g[u].size();++i){
                Edge e = g[u][i];
                if(e.rc() > 0 && parent[e.v] == undef){
                    q.push(e.v);
                    parent[e.v] = mp(u,i);
                }
            }
        }
        //증가경로를 못찾았다
        if(parent[t]==undef)break;
        //증가경로를 통해 플로우를 흘린다.
        int amt = INF;
        for(int p=t;parent[p].ff!=p;p=parent[p].ff){
            Edge e = g[parent[p].ff][parent[p].ss];
            amt = min(amt, e.rc());
        }
        for(int p=t;parent[p].ff!=p;p=parent[p].ff){
            push(g, parent[p].ff, parent[p].ss, amt);
        }
        ans += amt;
    }
    return ans;
}
int ok(int totalWins)
{
    if(*max_element(wins.begin()+1,wins.end())>=totalWins)return false;
    //그래프를 구성하자 소스 0 싱크 1    
    vector< vector< Edge> > graph(N+M+2);
    for(int i=0;i<M;++i){
        //소스에서 경기로
        add_edge(graph, 0, i+2, 1);
        //경기에서 선수로
        for(int j=0;j<2;++j)add_edge(graph, 2 + i, 2+M+match[i][j], 1);
    }
    for(int i=0;i<N;++i){
        int maxWin = (i==0)?totalWins:totalWins-1;
        //선수에서 싱크로
        add_edge(graph, 2+M+i, 1, maxWin - wins[i]);
    }
    return networkFlow(0,1,graph) == M;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        wins = vector<int>(N);
        match = vector< vector<int> >(M,vector<int>(2));
        for(int i=0;i<N;++i)scanf("%d",&wins[i]);
        int ub = 0;
        for(int i=0;i<M;++i){
            scanf("%d%d",&match[i][0],&match[i][1]);
            if(match[i][0] == 0 || match[i][1] == 0)++ub;
        }
        bool valid = false;
        for(int w = wins[0]; w <= wins[0] + ub; ++w){
            if(ok(w)){
                printf("%d\n",w);
                valid = true;
                break;
            }
        }
        if(!valid)printf("-1\n");
    } 
    //fclose(stdin);
}

