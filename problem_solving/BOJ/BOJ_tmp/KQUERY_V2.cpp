//KQUERY_V2.cpp
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
typedef pair<pair<int, int>, pair<int, int> > piii;
const int INF = 987654321;
const long long LINF = 9876543212345;

int N,M;
pii a[30005];
piii q[200005];
int ans[200005];
vector<int> s;
void build(int id=1, int l=0, int r=N-1)
{
	if(l==r){
		s[id]=1;
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1,mid+1,r);
	s[id] = s[id<<1] + s[id<<1|1];
}

void update(int p, int id=1, int l=0, int r=N-1)
{
	if(l==r){
		s[id]=0;
		return;
	}
	int mid = (l+r)>>1;
	if(p<=mid)update(p, id<<1, l, mid);
	else update(p, id<<1|1, mid+1, r);
	s[id] = s[id<<1] + s[id<<1|1];
}
int query(int x, int y, int id=1, int l=0, int r=N-1)
{
	if(y<l || r<x)return 0;
	if(x<=l && r<=y)return s[id];
	int mid = (l+r)>>1;
	return query(x,y,id<<1,l,mid)+query(x,y,id<<1|1,mid+1,r);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int i,j,k;
	scanf("%d",&N);
	for(i=0;i<N;++i){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	s = vector<int>(N<<2,0);
	build();
	scanf("%d",&M);
	for(i=0;i<M;++i){
		scanf("%d%d%d",&q[i].ss.ff,&q[i].ss.ss,&q[i].ff.ff);
		q[i].ff.ss = i;
	}
	sort(a,a+N);
	sort(q,q+M);
	int cnt = 0;
	for(i=0;i<M;++i){
		int x = q[i].ff.ss;
		while(cnt < N && a[cnt].ff <= q[i].ff.ff)
			update(a[cnt++].ss);
		ans[x] = query(q[i].ss.ff-1,q[i].ss.ss-1);
	}
	for(i=0;i<M;++i)printf("%d\n",ans[i]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
