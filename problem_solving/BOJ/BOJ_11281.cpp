#include <bits/stdc++.h>
using namespace std;
int n,m;

int neg(int x)
{
	return x<=n?x+n:x-n;
}
vector<int> adj[20005];
vector<int> radj[20005];
int visited[20005];
int vcnt;
stack<int> stk;

void dfs(int cur)
{
	visited[cur]=0;
	for(int i=0;i<adj[cur].size();++i){
		int nxt=adj[cur][i];
		if(visited[nxt]==-1){
			dfs(nxt);
		}
	}
	stk.push(cur);
}

void dfs2(int cur)
{
	visited[cur]=vcnt;
	for(int i=0;i<radj[cur].size();++i){
		int nxt=radj[cur][i];
		if(!visited[nxt]){
			dfs2(nxt);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<0)x=-x+n;
		if(y<0)y=-y+n;
		adj[neg(x)].push_back(y);
		adj[neg(y)].push_back(x);
		radj[y].push_back(neg(x));
		radj[x].push_back(neg(y));
	}
	memset(visited,-1,sizeof(visited));
	for(int i=1;i<(n<<1|1);++i){
		if(visited[i]==-1){
			dfs(i);
		}
	}
	while(!stk.empty()){
		int cur=stk.top();
		stk.pop();
		if(!visited[cur]){
			++vcnt;
			dfs2(cur);
		}
	}
	for(int i=1;i<=n;++i){
		if(visited[i]==visited[i+n]){
			puts("0");
			return 0;
		}
	}
	puts("1");
	for(int i=1;i<=n;++i){
        printf("%d ",visited[i]>visited[i+n]);
	}
}