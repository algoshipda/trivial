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
int a[100005];
struct SegmentTree{
	int n;
	vector<int> s;
	SegmentTree():n(N),s(N<<2,INT_MAX){}
	//[l,r)
	void build(int id=1, int l=0, int r=N)
	{
		//l+1==r, leaf
		if(r-l<2){
			s[id] = INT_MAX;
			return;
		}
		int mid = (l+r)>>1;
		build(id<<1, l, mid);   //[l, mid)
		build(id<<1|1, mid, r); //[mid, r)
		s[id] = min(s[id<<1] , s[id<<1|1]);
	}	

	//call : modify(p, x)
	//modify a[p] -> x, s[id] already has a[p] so just add s[id] + x - a[p]
	void modify(int p, int x, int id=1, int l=0, int r=N)
	{
		s[id] = min(s[id], x);
		if(r-l<2){
			return;
		}
		int mid = (l+r)>>1;
		if(p < mid)
			modify(p, x, id<<1, l, mid);
		else
			modify(p, x, id<<1|1, mid, r);
	}

	//call : sum(x,y)
	int query(int x, int y, int id=1, int l=0, int r=N)
	{
		if(y <= l || r <= x) return INT_MAX;
		if(x <= l && r <= y) return s[id];
		int mid = (l+r)>>1;
		return min(query(x, y, id<<1, l, mid),
				query(x, y, id<<1|1, mid, r));
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&M);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%d",&a[i]);
	SegmentTree mtr;
	SegmentTree Mtr;
	mtr.build();
	Mtr.build();
	for(i=0;i<N;++i)mtr.modify(i,a[i]),Mtr.modify(i,-a[i]);
	for(i=0;i<M;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		--a;
		//[a,b)
		printf("%d %d\n",mtr.query(a,b),-Mtr.query(a,b));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
