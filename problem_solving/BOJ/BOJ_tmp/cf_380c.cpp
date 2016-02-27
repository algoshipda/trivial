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


struct Node{
	int o;
	int c;
	int t;
	Node():o(0),c(0),t(0){}
};
char s[1000005];
int N,M;
vector<Node> st;

void build(int id = 1, int l = 0, int r = N-1)
{
	if(l == r){
		st[id].o = s[l]=='(';
		st[id].c = s[l]==')';
		return;
	}
	int mid = (l+r)>>1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	int tmp = min(st[id<<1].o, st[id<<1|1].c);
	st[id].t = st[id<<1].t + st[id<<1|1].t + tmp;
	st[id].o = st[id<<1].o + st[id<<1|1].o - tmp;
	st[id].c = st[id<<1].c + st[id<<1|1].c - tmp;
}

Node query(int x, int y, int id=1, int l=0, int r=N-1)
{
	if(y<l || r<x) return Node();
	if(x <=l  && r <= y) return st[id];
	int mid = (l+r)>>1;
	Node a = query(x,y,id<<1,l,mid);
	Node b = query(x,y,id<<1|1,mid+1,r);
	int tmp = min(a.o,b.c);
	Node ret;
	ret.t = a.t + b.t + tmp;
	ret.o = a.o + b.o - tmp;
	ret.c = a.c + b.c - tmp;
	return ret;
	 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%s",s);
	scanf("%d",&M);
	int i,j,k;
	N = strlen(s);
	st = vector<Node>(N<<2);
	build();
	for(i=0;i<M;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",query(a-1,b-1).t<<1);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
