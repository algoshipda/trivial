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
int a[100005];
vector<int> s[400005];
void build(int id = 1, int l=0, int r=N-1)
{
	if(l==r){
		s[id] = vector<int>(1);
		s[id][1] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1,l, mid);
	build(id<<1|1, mid+1, r);
	s[id].resize(r-l+1);
	merge(s[id<<1].begin(),s[id<<1].end(),s[id<<1|1].begin(),s[id<<1|1].end(),s[id].begin());
}

int query(int x, int y, int k, int id = 1, int l=0, int r=N-1)
{
	printf("%d %d %d\n",x,y,k);
	if(r<x || y<l)return 0;
	if(x<=l && r<=y)return upper_bound(s[id].begin(),s[id].end(),k)-s[id].begin();
	int mid = (l+r)>>1;
	return query(x,y,k,l,mid) + query(x,y,k,mid+1,r);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&Q);
	int i,j,k;
	for(i=0;i<N;++i)scanf("%d",&a[i]);
	build();
	for(i=0;i<Q;++i){
		int l = 0;
		int r = 1234567890;
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		while(l<r){
			int mid = (l+r+1)>>1;
			if(query(a,b,mid)>=c){
				r = mid;
			}else l = mid+1;
		}
		printf("%d\n",l);
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
