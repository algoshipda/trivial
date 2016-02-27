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
int s[400005];
bool lazy[400005];

void update(int id, int l, int r)
{
	lazy[id] ^= 1;
	s[id] = (r-l+1) - s[id];
}

void shift(int id, int l, int r)
{
	int mid = (l+r)>>1;
	if(!lazy[id]) return;
	update(id<<1, l, mid);
	update(id<<1|1, mid+1, r);
	lazy[id] = 0;
}
void inversion(int x, int y, int id=1, int l=0, int r=N-1)
{
	if(y<l || r<x)return;
	if(x<=l && r<=y){
		update(id, l, r);
		return;
	}
	shift(id, l, r);
	int mid = (l+r)>>1;
	inversion(x, y, id<<1, l, mid);
	inversion(x, y, id<<1|1, mid+1, r);
	s[id] = s[id<<1] + s[id<<1|1];
}

int query(int x, int y, int id=1, int l=0, int r=N-1)
{
	if(y<l || r<x)return 0;
	if(x<=l && r<=y)return s[id];
	shift(id, l, r);
	int mid = (l+r)>>1;
	return query(x,y,id<<1,l,mid) + query(x,y,id<<1|1,mid+1,r);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&M);
	int i,j,k;
	for(i=0;i<M;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a) printf("%d\n",query(b-1,c-1));
		else inversion(b-1,c-1);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

