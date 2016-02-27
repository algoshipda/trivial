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
int a[300005];

struct Node{
	int sz;
	vector<int> perm;
	Node(){perm=vector<int>();}
};

vector<Node> s;

void build(int id=1, int l=0, int r=N-1)
{
	if(l==r){
		s[id].perm = vector<int>();
		s[id].perm.pb(a[l]);
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	vector<int>& a = s[id<<1].perm;
	vector<int>& b = s[id<<1|1].perm;
	int i=0,j=0;
	s[id].perm = vector<int>(r-l+1,0);
	merge(a.begin(),a.end(),b.begin(),b.end(),s[id].perm.begin());
}

int query(int x, int y, int k, int id=1, int l=0, int r=N-1)
{
	if(y<l || r<x)return 0;
	if(x<=l && r<=y)return r-l+1-(upper_bound(s[id].perm.begin(),s[id].perm.end(),k)-s[id].perm.begin());
	int mid = (l+r)>>1;
	return query(x,y,k,id<<1,l,mid)+query(x,y,k,id<<1|1,mid+1,r);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	s = vector<Node>(N<<2);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%d",&a[i]);
	build();
	scanf("%d",&M);
	for(i=0;i<M;++i){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		printf("%d\n",query(x-1,y-1,k));
	}
	
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
