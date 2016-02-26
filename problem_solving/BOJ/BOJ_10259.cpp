#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct Edge
{
    int v, c;
    Edge(){}
    Edge(int _v, int _c):v(_v), c(_c){}
};
const int MN = 2e5 + 10;
int n, m;
vector<Edge> adj[MN];
int color[MN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(Edge(v, c));
        adj[v].push_back(Edge(u, c));
    }
    memset(color, -1, sizeof(color));
    for(int u = 1; u <= n; ++u){
        for(auto edge: adj[u]){
            if(edge.c == 2){
                if(color[u] == 0 || color[v] == 0){
                    cout << "impossible" << '\n';
                    return 0;
                }
            }               
        }
    }
}
