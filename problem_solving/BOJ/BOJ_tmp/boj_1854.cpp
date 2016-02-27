#include <bits/stdc++.h>
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
typedef pair<long long, int> pli;
const int INF = 987654321;
const long long LINF = 9876543212345;

int N,M,K;
vector<int> adj[1002];
vector<int> cost[1002];
priority_queue<lld> kth[1002];

void dijkstra()
{
    priority_queue<pli, vector<pli>, greater<pli> > q;
    q.push(mp(0,1));
    kth[1].push(0);
    while(!q.empty()){
        int cur = q.top().ss;
        lld co = q.top().ff;
        q.pop();
        for(int i=0;i<sz(adj[cur]);++i){
            int next = adj[cur][i];
            lld c = co + cost[cur][i];
            if((int)kth[next].size()<K){
                kth[next].push(c);
                q.push(mp(c,next));
            }else{
                if(kth[next].top()>=c){
                    kth[next].pop();
                    kth[next].push(c);
                    q.push(mp(c,next));
                }
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif

    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        adj[a].pb(b);
        cost[a].pb(c);
    }
    dijkstra();
    for(int i=1;i<=N;++i)printf("%lld\n",(int)kth[i].size()==K?kth[i].top():-1);
    
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

