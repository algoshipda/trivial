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
const long long MOD = 1000000007;
int N,K,P;
int deg[300005];
int rdeg[300005];
vector<int> adj[300005];
vector<int> rev[300005];
vector<int> order;
vector<int> order2;
lld M;
lld m;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&N,&K,&P);
	int i,j,k;
	for(i=0;i<P;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[b].pb(a);
		rev[a].pb(b);
		deg[a]++;
		rdeg[b]++;
	}
	priority_queue<int> pq;
	vector<int> perm(K,0);
	for(i=0;i<K;++i)if(deg[i]==0)pq.push(-i);
	int x = N-K;
	while(!pq.empty()){
		int cur = -pq.top();
		perm[cur] = x++;
		pq.pop();
		for(i=0;i<sz(adj[cur]);++i){
			int next = adj[cur][i];
			if(deg[next]){
				--deg[next];
				if(deg[next]==0)pq.push(-next);
			}
		}
	}
	for(i=K-1;i>=0;--i){
		M *= N;
		M += perm[i];
		M %= MOD;
	}
	for(i=0;i<K;++i)if(rdeg[i]==0)pq.push(-i);
	x = K;
	while(!pq.empty()){
		int cur = -pq.top();
		perm[cur] = --x;
		pq.pop();
		for(int i=0;i<sz(rev[cur]);++i){
			int next = rev[cur][i];
			if(rdeg[next]){
				--rdeg[next];
				if(rdeg[next]==0)pq.push(-next);
			}
		}
	}
	for(i=K-1;i>=0;--i){
		m *= N;
		m += perm[i];
		m %= MOD;
	}
	printf("%lld\n",((M-m)%MOD+MOD)%MOD);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
