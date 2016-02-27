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

int N,M,K;
int a[1000005];
lld s[4000005];

void build(int id=1, int l=0, int r=N-1)
{
	if(l==r){
		s[id] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1,mid+1,r);
	s[id] = s[id<<1] + s[id<<1|1];
}

void update(int pos, int val, int id=1, int l=0, int r=N-1)
{
	if(l==r){
		if(pos!=l)return;
		s[id] = val;
		return;
	}
	int mid = (l+r)>>1;
	if(pos<=mid){
		update(pos, val, id<<1, l, mid);
	}else{
		update(pos, val, id<<1|1, mid+1,r);
	}
	s[id] = s[id<<1] + s[id<<1|1];
}

lld query(int x, int y, int id=1, int l=0, int r=N-1)
{
	if(x>r || y<l)return 0;
	if(x<=l && r<=y)return s[id];
	int mid = (l+r)>>1;
	return query(x,y,id<<1,l,mid) + query(x,y,id<<1|1,mid+1,r);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d",&N,&M,&K);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%d",&a[i]);
	build();
	for(i=0;i<M+K;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
			update(y-1,z);
		else{
			printf("%lld\n",query(y-1,z-1));
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
