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

int N,Q;

int sz;
pii r[400005];
pii c[400005];
pii t[400005];

int x[200005];
int y[200005];
char o[200005];

vector<int> v;
map<int,int> m;
int im[400005];

int build(int id=1, int l=0, int r=sz-1)
{
	if(l==r){
		r[id] = c[id] = t[l];
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	r[id] = 
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&Q);
	int i,j,k;
	for(i=0;i<Q;++i){
		scanf("%d %d %c",&x[i],&y[i],&m[i])
		v.pb(x[i]);
		v.pb(y[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	sz = sz(v);
	for(i=0;i<sz(v);++i){
		t[i] = mp(v[i],i); 
	}
	build();
	for(i=0;i<sz(v);++i){
		m[v[i]] = i;
		im[i] = v[i];
	}	


#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
