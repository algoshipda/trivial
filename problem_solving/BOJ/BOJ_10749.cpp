#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, c;
    Edge(int _u = 0, int _v = 0, int _c = 0) : u(_u), v(_v), c(_c) {}
    bool operator < (const Edge& rhs) const
    {
        return c > rhs.c;
    }
};

const int MN = 2005;
int num[MN], n;
Edge edges[MN * MN];
int p[MN], r[MN];
int findSet(int u)
{
    if(u == p[u]) return u;
    return p[u] = findSet(p[u]);
}

void mergeSet(int u, int v)
{
    if(r[u] < r[v]) swap(u, v);
    p[v] = u;
    if(r[u] == r[v]) r[u]++;    
}
int main()
{
    cin >> n;
    int k = 0;
    for(int i = 0; i < n; ++i){
        p[i] = i;
        cin >> num[i];
        for(int j = 0; j < i; ++j){
            edges[k++] = Edge(i, j, num[i] ^ num[j]);
        }
    }
    sort(edges, edges + k);
    long long ans = 0;
    for(int i = 0; i < k; ++i){
        Edge& e = edges[i];
        int u = findSet(e.u);
        int v = findSet(e.v);
        if(u == v) continue;
        ans += e.c;
        mergeSet(u, v);
    }
    cout << ans << '\n';

}

