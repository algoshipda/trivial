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

const int INF = 987654321;
const long long LINF = 9876543212345;

int T,K,M,P;
vector< vector<int> > adj;
vector<int> in;
vector<int> node_max_cnt;
vector<int> node_max;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&T);
	for(int t = 1; t <= T ; ++t){
		scanf("%d%d%d",&K,&M,&P);
		int i,j,k;
		adj = vector< vector<int> > (M+1,vector<int>(M+1));
		in = vector<int>(M+1,0);
		node_max_cnt = vector<int>(M+1,0);
		node_max = vector<int>(M+1,0);
		for(i=0;i<P;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			adj[a].pb(b);
			in[b]++;
		}
		queue<int> q;
		for(i=1;i<=M;++i){
			node_max[i] = in[i]==0;
			if(node_max[i])q.push(i);
		}
		
		while(!q.empty()){
			int cur =q.front();q.pop();
			if(node_max_cnt[cur]>=2)node_max[cur]++;
			for(i=0;i<sz(adj[cur]);++i){
				int nxt = adj[cur][i];
				if(in[nxt]){
					if(node_max[cur] > node_max[nxt]){
						node_max[nxt] = node_max[cur];
						node_max_cnt[nxt] = 1;
					}else if(node_max[cur] == node_max[nxt])
						++node_max_cnt[nxt];
					--in[nxt];
					if(!in[nxt])q.push(nxt);
				}
			}
		}
		printf("%d %d\n",t,node_max[M]);
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
