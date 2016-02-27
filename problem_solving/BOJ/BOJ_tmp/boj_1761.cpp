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
vector< vector<int> > adj;
vector< vector<int> > dist;

vector<int> visited;
vector<int> depth;
vector<int> order;  
vector<int> pos;    //position in order
vector<int> origin; //original number
vector<int> s;      //segment tree
int num;

void dfs(int a, int d)
{
	visited[a] = 1;
	int mynum = num++;
	pos[a] = sz(order);
	origin[mynum] = a;
	depth[a] = d;
	order.pb(mynum);
	for(int i=0;i<sz(adj[a]);++i){
		int next = adj[a][i];
		if(!visited[next]){
			dfs(next, d + dist[a][i]);
			order.pb(mynum);
		}
	}
}
void build(int id=1, int l=0, int r = N<<1)
{
	if(l==r){
		s[id] = INF;
		if(l>=sz(order))return;
		s[id] = order[l];
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	s[id] = min(s[id<<1], s[id<<1|1]);	
}

int query(int x, int y, int id = 1, int l = 0, int r = N<<1)
{
	if(y<l || r<x)return INF;
	if(x<=l && r<=y)return s[id];
	int mid = (l+r)>>1;
	return min(query(x,y,id<<1,l,mid),query(x,y,id<<1|1,mid+1,r));	
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	adj = dist = vector< vector<int> >(N+1, vector<int>());
	visited = depth = pos = origin = vector<int>(N+1, 0);
	for(i=1;i<N;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		adj[a].pb(b);
		adj[b].pb(a);
		dist[a].pb(c);
		dist[b].pb(c);
	}
	dfs(1,0);
	s = vector<int>((N<<1+1)<<2,INF);
	build();
	scanf("%d",&M);
	for(i=1;i<=M;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		if(pos[a]>pos[b])swap(a,b);
		int lca = query(pos[a],pos[b]);
		printf("%d\n",depth[a] + depth[b] - (depth[origin[lca]]<<1));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
