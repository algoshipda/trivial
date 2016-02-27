#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define pb push_back
using namespace std;
int n,m;
vector< vector<int> > adj;
vector<int> vis, order;
vector<int> in;
vector<int> topologicalSort()
{
        vis = vector<int>(n+1,0);
        priority_queue<int> q;
        for(int i=1;i<=n;++i){
                if(!in[i]){
                        q.push(-i);
                        vis[i]=1;
                }
        }
        while(!q.empty()){
                int cur = -q.top();
                order.pb(cur);
                q.pop();
                for(int i=0;i<(int)adj[cur].size();++i){
                        int next = adj[cur][i];
                        --in[next];
                        if(!in[next] && !vis[next]){
                                q.push(-next);
                                vis[next]=1;
                        }
                }
        
        }
        return order;
}
int main()
{
        scanf("%d%d",&n,&m);
        adj = vector< vector<int> >(n+1);
        in = vector<int>(n+1,0);
        for(int i=0;i<m;++i){
                int a,b;
                scanf("%d%d",&a,&b);
                adj[a].pb(b);
                ++in[b];
        }
        for(int i=1;i<=n;++i)
                sort(adj[i].begin(),adj[i].end());
        vector<int> ans = topologicalSort();
        for(int i=0;i<(int)ans.size();++i)
                printf("%d ",ans[i]);
                
        return 0;
}
