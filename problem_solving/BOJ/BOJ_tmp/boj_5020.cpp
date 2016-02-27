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

int N,M;

int group[100005];
vector<int> adj[100005];

int gcnt=1;
void process(int x, bool& update)
{
	int cnt = 0;
	for(int i=0;i<sz(adj[x]);++i){
		if(group[x] == group[adj[x][i]])++cnt;
	}
	if(cnt>=2){
		group[x]^=1;
		update = true;
		gcnt=2;
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int i,j,k;
	scanf("%d%d",&N,&M);
	for(i=0;i<M;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bool update = true;
	while(update){
		update = false;
		for(i=1;i<=N;++i)process(i,update);
	}
	printf("%d\n",gcnt);
	if(gcnt==2){
		for(i=1;i<=N;++i){
			if(group[i])printf("%d ",i);
		}
		puts("");
	}
	for(i=1;i<=N;++i)if(!group[i])printf("%d ",i);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
