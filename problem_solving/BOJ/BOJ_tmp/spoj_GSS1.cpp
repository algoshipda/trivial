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

const int INF = 1073741823;
const long long LINF = 9876543212345;

struct Node{
	int lsum;
	int rsum;
	int msum;
	int as;
	Node(){
		lsum=rsum=msum=as=-INF;
	}
};
int N,M;
Node s[200005];
int a[200005];

void build(int id=1, int l=0, int r=N-1)
{
	if(l==r){
		s[id].lsum = s[id].rsum = s[id].msum = s[id].as = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	s[id].lsum = max(s[id<<1].lsum, s[id<<1].as + s[id<<1|1].lsum);
	s[id].rsum = max(s[id<<1|1].rsum, s[id<<1|1].as + s[id<<1].rsum);
	s[id].msum = max(s[id<<1].msum, max(s[id<<1|1].msum, s[id<<1].rsum + s[id<<1|1].lsum));
	s[id].as = s[id<<1].as + s[id<<1|1].as;
}

Node query(int x, int y, int id=1, int l=0, int r=N-1)
{
	if(y<l || r<x) return Node();
	if(x<=l && r<=y) {
		return s[id];
	}		
	int mid = (l+r)>>1;
	Node lq = query(x,y, id<<1, l, mid);
	Node rq = query(x,y, id<<1|1, mid+1, r);
	Node ret;
	ret.lsum = max(lq.lsum, lq.as+rq.lsum);
	ret.rsum = max(rq.rsum, rq.as+lq.rsum);
	ret.as = lq.as + rq.as;
	ret.msum = max(lq.msum, max(rq.msum, lq.rsum + rq.lsum));
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%d",&a[i]);	
	build();
	scanf("%d",&M);
	for(i=0;i<M;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		Node q = query(x-1,y-1);
		printf("%d\n",max(q.msum,max(q.lsum,q.rsum)));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
