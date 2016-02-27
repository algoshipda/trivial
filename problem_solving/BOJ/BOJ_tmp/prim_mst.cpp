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

int N,M;

vector<int> adj[1005];
vector<int> cost[1005];

int prim()
{
    vector<int> mincost(N+1,INF);
    vector<int> used(N+1,0);
    mincost[1] = 0;
    int res = 0;
    for(int i=0;i<N;++i){
        int midx = -1;
        for(int j=1;j<=N;++j){
            if(!used[j] && (midx==-1 || mincost[midx] > mincost[j])){
                midx = j;
            }
        }
        used[midx] = 1;
        res += mincost[midx];
        for(int j=0;j<(int)adj[midx].size();++j){
            int v = adj[midx][j];
            mincost[v] = min(mincost[v], cost[midx][j]);
        }
    }
    return res;
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].pb(b);
        cost[a].pb(c);
        adj[b].pb(a);
        cost[b].pb(c);
    }   
    printf("%d\n",prim());
}

