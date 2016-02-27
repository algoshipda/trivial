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

int N;
vector<int> s;
vector<int> lazy;
void build(int id=1, int l=0, int r=N-1)
{
	if(l==r){
		s[id] = 0;
		lazy[id] = 0;
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
}

void shift(int id)
{
	if(lazy[id])
		lazy[id<<1] = lazy[id<<1|1] = lazy[id];
	lazy[id] = 0;
}

void update(int x, int y, int c, int id=1, int l=0, int r=N-1)
{
	if(y<l || r<x) return;
	if(x<=l && r<=y){
		lazy[id] = c;
		return;
	}
	int mid = (l+r)>>1;
	shift(id);
	update(x,y,c,id<<1,l,mid);
	update(x,y,c,id<<1|1,mid+1,r);
}

set<int> ans;
void count(int id = 1, int l = 0, int r = N-1)
{
	if(lazy[id]){
		ans.insert(lazy[id]);
		return;
	}
	if(l==r)return;
	int mid = (l+r)>>1;
	count(id<<1, l, mid);
	count(id<<1|1, mid+1, r);
}


int T;
vector<int> pos;
vector<pii> query;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		pos.clear();
		ans.clear();
		query.clear();
		scanf("%d",&N);
		int i,j,k;
		for(i=0;i<N;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			pos.pb(a);
			pos.pb(b);
			query.pb(mp(a,b));
		}
		sort(all(pos));
		pos.erase(unique(all(pos)),pos.end());
		N = sz(pos);
		s = vector<int>(N<<2+1,0);
		lazy = vector<int>(N<<2+1,0);
		build();
		for(i=0;i<sz(query);++i){
			int lidx = lower_bound(all(pos),query[i].ff)-pos.begin();
			int ridx = lower_bound(all(pos),query[i].ss)-pos.begin();
			update(lidx, ridx, i+1);
		}
		count();
		printf("%d\n",sz(ans));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
