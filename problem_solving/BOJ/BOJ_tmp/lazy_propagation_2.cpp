#include <cstdio>
#include <algorithm>
#include <vector>

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
lld a[100005];
lld s[400005];
lld lazy[400005];
void build(int id=1, int l=0, int r = N-1)
{
	lazy[id] = 0;
	if(l==r){
		s[id] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	s[id] = s[id<<1] + s[id<<1|1];
}

void update(int id, int l, int r, lld c)
{
	lazy[id] += c;
	s[id] += (r-l+1)*c;
}

void shift(int id, int l, int r)
{
	int mid = (l+r)>>1;
	update(id<<1, l, mid, lazy[id]);
	update(id<<1|1, mid+1, r, lazy[id]);
	lazy[id] = 0;
}
void increase(int x, int y, lld c, int id=1, int l=0, int r=N-1)
{
	if(r<x || y<l) return;
	if(x<=l && r<=y){
		update(id,l,r,c);
		return;
	}
	shift(id, l, r);
	int mid = (l+r)>>1;
	increase(x,y,c,id<<1,l,mid);
	increase(x,y,c,id<<1|1,mid+1,r);
	 s[id] = s[id<<1] + s[id<<1|1];
}

lld query(int x, int y, int id=1, int l=0, int r=N-1)
{
	if(r<x || y<l) return 0;
	if(x<=l && r<=y) return s[id];
	shift(id, l, r);
	int mid = (l+r)>>1;
	return query(x,y,id<<1, l, mid) + query(x,y,id<<1|1, mid+1, r);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&M);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%lld",&a[i]);
	build();
	for(i=0;i<M;++i){
		char o;
		int a,b,c;
		scanf(" %c ",&o);
		if(o=='Q'){
			scanf("%d %d",&a,&b);
			printf("%lld\n",query(a-1,b-1));
		}else{
			scanf("%d %d %d",&a,&b,&c);
			increase(a-1,b-1,c);
		}
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
