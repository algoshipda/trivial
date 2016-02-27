#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n,m;
int dp[100005];
vector<int> adj[100005];

int rec(int x)
{
	int& ret=dp[x];
	if(ret!=-1)return ret;
	ret=1;
	for(int i=0;i<adj[x].size();++i){
		if(adj[x][i]<x){
			ret=max(ret,1+rec(adj[x][i]));
		}
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(dp,-1,sizeof(dp));
	lld ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,rec(i)*(lld)adj[i].size());
	}
	cout<<ans<<endl;
}
