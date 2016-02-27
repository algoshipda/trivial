#include <algorithm>
#include <cstdio>
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

vector< lld > a;
vector< lld > s;
vector< lld > lazy;

void build(int id=1, int l=0, int r=N-1)
{
	if(l==r){
		s[id]=a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1,mid+1,r);
	s[id] = s[id<<1] + s[id<<1|1];
}	

void update(lld c, int id, int l, int r)
{
	printf("        update %d %d %d\n",id, l, r);
	lazy[id] += c;
	s[id] += (r-l+1)*c;
}

//이미 있던 lazy를 없앰 ?
void shift(int id, int l, int r)
{
	printf("         shift %d %d %d\n",id,l,r);	
	int mid = (l+r)>>1;
	if(!lazy[id])return;
	update(lazy[id], id<<1, l, mid);
	update(lazy[id], id<<1|1, mid+1, r);
	lazy[id] = 0;
}

void increase(int x, int y, lld c, int id=1, int l=0, int r=N-1)
{
	if(y<l || r<x)return;
	if(x<=l && r<=y){
		printf("  increase %d %d %d %d %d\n",x,y,id,l,r);
		update(c, id, l, r);
		return;
	}	
	shift(id, l, r);
	int mid = (l+r)>>1;
	increase(x,y,c,id<<1,l,mid);
	increase(x,y,c,id<<1|1,mid+1,r);
	s[id] = s[id<<1] + s[id<<1|1];
}

lld sum(int x, int y, int id=1,int l=0, int r=N-1)
{
	if(y<l || r<x)return 0;
	if(x<=l && r<=y)
		return s[id];
	shift(id,l,r);
	int mid = (l+r)>>1;
	return sum(x,y,id<<1,l,mid) + sum(x,y,id<<1|1,mid+1,r);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&M);
	int i,j,k;
	for(i=0;i<N;++i){
		int x;
		scanf("%d",&x);
		a.pb(x);
	}
	s = vector<lld>(N<<2,0);
	lazy = vector<lld>(N<<2,0);
	build();
	for(i=0;i<M;++i){
		char o;
		int a,b,c;
		scanf(" %c ",&o);
		if(o=='Q'){
			scanf("%d %d",&a,&b);
			printf("%lld\n", sum(a-1,b-1));
		}else{
			scanf("%d %d %d",&a,&b,&c);
			increase(a-1,b-1,c);
			printf("------------------------\n");
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
