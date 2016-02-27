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
typedef pair<int, pair<int, int> > piii;
const int INF = 987654321;
const long long LINF = 9876543212345;

int N,R,D;

map<int, int> s;
vector<pii> inf;
vector<int> adj[100005];
vector<piii> p;
map<int, int> c;
vector<int> v;
vector<int> xp;
vector<int> yp;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&R);
	int i,j,k;
	for(i=0;i<N;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		p.pb(mp(a,mp(b,i)));
		inf.pb(mp(a,b));
		xp.pb(a);
		yp.pb(b);
	}
	sort(all(xp));
	sort(all(yp));
	xp.erase(unique(all(xp)),xp.end());
	yp.erase(unique(all(yp)),yp.end());
	scanf("%d",&D);
	sort(all(p));	
	for(i=0;i<N;++i)c[xp[i]]=i;
	for(i=0;i<N;++i){
		int ly = s.lower_bound(s.begin(),s.end(),p.yy);
		
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
