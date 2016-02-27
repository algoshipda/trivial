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

struct Line{
	int x,y1,y2,left;
	Line(int _x, int _y1, int _y2, int _left):x(_x),y1(_y1),y2(_y2),left(_left){}
	bool operator < (const Line a ) const{
		if(x!=a.x)return x<a.x;
		return left>a.left;
	}
};
int N;
int s[150000];
int cnt[150000];
vector<Line> v;


void increase(int x, int y, int c, int id=1, int l=0, int r = 30001)
{
	if(y<l || r<x) return;
	if(x<=l && r<=y){
		cnt[id] += c;
	}else{
		int mid = (l+r)>>1;
		increase(x,y,c,id<<1,l,mid);
		increase(x,y,c,id<<1|1,mid+1,r);
	}
	s[id] = 0;
	if(cnt[id]>0) s[id] = (r-l+1);
	else if(cnt[id]==0) s[id] = s[id<<1] + s[id<<1|1];
}

int query(int x, int y, int id=1, int l=0, int r = 30001)
{
	if(y<l || r<x)return 0;
	if(x<=l && r<=y)return s[id];
	int mid = (l+r)>>1;
	return query(x,y,id<<1,l,mid) + query(x,y,id<<1|1,mid+1,r);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<N;++i){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		v.pb(Line(x1,y1,y2,1));
		v.pb(Line(x2,y1,y2,-1));
	}
	
	sort(all(v));
	int cx = v[0].x;
	int ans = 0;
	for(i=0;i<sz(v);++i){
		ans += query(0,30001)*(v[i].x - cx);
		increase(v[i].y1,v[i].y2-1,v[i].left);
		cx = v[i].x;
	}
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
