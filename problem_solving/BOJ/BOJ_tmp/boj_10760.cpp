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

int p[100005];
int r[100005];
int N;
vector<pii> H;
map<int, int> m;
map<int, int> pos;
vector<int> P;
int trapped[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<=N+1;++i)p[i] = i;
	for(i=0;i<=N+1;++i)r[i] = 1;
	for(i=0;i<N;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		H.pb(mp(a,b));
		P.pb(b);
	}
	sort(all(P));
	sort(H.rbegin(),H.rend());
	for(i=0;i<N;++i)pos[P[i]] = i;
	for(auto& h : H){
		m[h.ss]=h.ff;
		map<int,int>::iterator lit = m.find(h.ss);
		map<int,int>::iterator rit = ++m.find(h.ss);
		if(lit!=m.begin()){
			--lit;
			int x = h.ss-lit->ff;
			if(x<=lit->ss && x<=h.ff){
				int l = pos[lit->ff];
				int r = pos[h.ss];
				for(i=l+1;i<=r;++i)trapped[i] = 1;
			}
		}
		if(rit!=m.end()){
			int x = rit->ff - h.ss;
			if(x<=rit->ss && x<=h.ff){
				int l = pos[h.ss];
				int r = pos[rit->ff];
				for(i=l+1;i<=r;++i)trapped[i] = 1;
			}
		}
	}
	int ans = 0;
	for(i=1;i<N;++i){
		if(trapped[i]){
			ans += P[i]-P[i-1];
		}
	}
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
