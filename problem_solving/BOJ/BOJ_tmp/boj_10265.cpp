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

int N,K;

vector<int> parent[1003];
int child[1003];
int visited[1003];
int cycle[1003];
int full[1003];
int dep[1003];
int dp[1003];
void full_dfs(int here, int& ecnt, int ccnt)
{
	visited[here] = ccnt;
	++ecnt;
	if(visited[child[here]]!=ccnt) full_dfs(child[here], ecnt, ccnt);
	for(int i=0;i<sz(parent[here]);++i)if(visited[parent[here][i]]!=ccnt) full_dfs(parent[here][i],ecnt,ccnt);
}

int cycle_dfs(int here, int depth, int ccnt)
{
	int ret = 0;
	visited[here] = ccnt + N;
	dep[here] = depth;
	if(visited[child[here]]==ccnt + N) ret = max(ret, dep[here] - dep[child[here]] + 1);
	else ret = max(ret, cycle_dfs(child[here], depth + 1, ccnt));
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	int i,j,k;
	for(i=1;i<=N;++i){
		int x;
		scanf("%d",&x);
		child[i] = x;
		parent[x].pb(i);
	}
	int component_cnt = 0;
	for(i=1;i<=N;++i){	
		if(!visited[i]){
			++component_cnt;
			int ecnt = 0;
			full_dfs(i, ecnt, component_cnt);
			full[component_cnt] = ecnt;
			cycle[component_cnt] = cycle_dfs(i, 0, component_cnt);
		}
	}
	dp[0] = 1;
	for(i=1;i<=component_cnt;++i){
		for(j=K;j>=0;--j){
			for(k=cycle[i];k<=full[i];++k)
				if(j-k>=0)dp[j] |= dp[j-k];
		}
	}
	
	for(i=K;i>=0;--i)if(dp[i]){printf("%d\n",i);break;}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
