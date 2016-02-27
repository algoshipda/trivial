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
    int v,f,c;
    Edge* r;
    Edge(int _v, int _c):v(_v),f(0),c(_c),r(0){}
    int rc()const{ return this->c - this->f; }
    void push(int amt){
        f += amt;
        r->f -= amt;
    }
};

void add_edge(vector< vector<Edge*> >& g, int u, int v, int c)
{
    Edge* ve = new Edge(v,c);
    Edge* ue = new Edge(u,c);
    ve->r = ue;
    ue->r = ve;
    g[u].pb(ve);
    g[v].pb(ue);
}

vector< vector<Edge*> > adj;
int wins[22];
int match[102][2];
int N,M;

int networkFlow(vector<vector< Edge* > >& adj, int source, int sink )
{
    int ans = 0;
    while(true)
    {
        pii UND = mp(-1,-1);
        vector<pii> parent(2+N+M,UND);
        queue<int> q;
        parent[source].first = source;
        q.push(source);
        while(!q.empty() && parent[sink] == UND){
            int u = q.front();q.pop();
            for(int i=0;i<(int)adj[u].size();++i){
                Edge* e = adj[u][i];
                if(e->rc()>0 && parent[e->v] == UND){
                    parent[e->v] = mp(u, i);
                    q.push(e->v);
                }
            }
        }
        if(parent[sink]==UND)break;
        int amt = INF;
        for(int p = sink; parent[p].ff != p; p = parent[p].ff)
            amt = min(amt, adj[parent[p].ff][parent[p].ss]->rc());
        
        for(int p = sink; parent[p].ff != p; p = parent[p].ff)
            adj[parent[p].ff][parent[p].ss]->push(amt);
        
        ans += amt;
    }
    return ans;
}
int ok(int totalWins)
{
    if(*max_element(wins+1,wins+N)>=totalWins)return 0;
    adj = vector< vector<Edge* > >(N+M+2);
    for(int i=0;i<M;++i){
        add_edge(adj, 0, 2+i, 1);
        for(int j=0;j<2;++j)add_edge(adj,2+i,2+M+match[i][j],1);
    }
    for(int i=0;i<N;++i){
        int maxWin = (i==0)?totalWins:totalWins-1;
        add_edge(adj, 2+i+M, 1, maxWin-wins[i]);
    }
    return networkFlow(adj,0,1)==M;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        int upperbound = 0;
        for(int i=0;i<N;++i)scanf("%d",&wins[i]);
        for(int i=0;i<M;++i){
            scanf("%d%d",&match[i][0],&match[i][1]);
            if(match[i][0] > match[i][1]) swap(match[i][0],match[i][1]);
            if(match[i][0] == 0)upperbound++;
        }
        upperbound+=wins[0];
        for(int i=wins[0];i<=upperbound;++i){
            if(ok(i)){
                printf("%d\n",i);
                break;
            }
            if(i==upperbound)printf("-1\n");
        }
    }
    //fclose(stdin);
}

