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


int a[100005];
struct SegmentTree{

	int n;
	vector<int> s;
	SegmentTree(int _n):n(_n),s(_n<<2,0){}
	//[l,r)
	void build(int id=1, int l=0, int r=n)
	{
		//l+1==r, leaf
		if(r-l<2){
			s[id] = a[l];
			return;
		}
		int mid = (l+r)>>1;
		build(id<<1, l, mid);   //[l, mid)
		build(id<<1|1, mid, r); //[mid, r)
		s[id] = s[id<<1] + s[id<<1|1];
	}	

	//call : modify(p, x)
	//modify a[p] -> x, s[id] already has a[p] so just add s[id] + x - a[p]
	void modify(int p, int x, int id=1, int l=0, int r=n)
	{
		s[id] += x - a[p];
		if(r-l<2){
			a[p] = x;
			return;
		}
		int mid = (l+r)>>1;
		if(p < mid)
			modify(p, x, id<<1, l, mid);
		else
			modify(p, x, id<<1|1, mid, r);
	}

	//call : sum(x,y)
	int sum(int x, int y, int id=1, int l=0, int r=n)
	{
		if(y <= l || r <= x) return 0;
		if(x <= l && r <= y) return s[id];
		int mid = (l+r)>>1;
		return sum(x, y, id<<1, l, mid) +
				sum(x, y, id<<1|1, mid, r);
	}

};
scanf("%d%d",&N,&M);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif

	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
