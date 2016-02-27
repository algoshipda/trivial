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
    int u,v,c;
    Edge(int _u=0, int _v=0, int _c=0):u(_u),v(_v),c(_c){}
    
    bool operator < (const Edge &b) const{
        if(this->c != b.c)return this->c < b.c;
        if(this->u != b.u)return this->u < b.u;
        return this->v < b.v;
    }
};

struct DisjointSet{
    int _sz;
    vector<int> parent;
    vector<int> height;
    
    
    DisjointSet(int __sz=0):_sz(__sz),height(__sz+1,1)
    {
        parent = vector<int>(__sz+1);
        for(int i=0;i<=__sz;++i)parent[i] = i;
    }
    
    int find(int u){
        if(u==parent[u])return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v)return;
        if(height[u]>height[v])swap(u,v);
        parent[u] = v;
        if(height[u] == height[v])++height[v];
    }
};
int N,M;
vector<Edge> E;

int kruskal()
{
    int res = 0;
    DisjointSet ds(N);
    int cnt = 0;
    for(int i=0;cnt<N-1;++i){
        int u = ds.find(E[i].u);
        int v = ds.find(E[i].v);
        if(u==v)continue;
        ++cnt;
        res += E[i].c;
        ds.merge(u,v);
    }
    return res;
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        E.pb(Edge(a,b,c));
    }
    sort(E.begin(),E.end());
    printf("%d\n",kruskal());
}

