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
typedef pair<long long, int> pli;

const int INF = 987654321;
const long long LINF = 9876543212345;

int T,N;
vector<lld> num;

lld gcd(lld a, lld b)
{
	return b?gcd(b,a%b):a;
}
lld process(int l, int r)
{
	if(l==r)return num[l];
	int mid = (l+r)>>1;
	lld ret = max(process(l,mid),process(mid+1,r));
	vector<pli> left;
	vector<pli> right;
	lld g = num[mid];
	for(int i=mid;i>=l;--i){
		g = gcd(g,num[i]);
		if(!left.empty() && left.back().ff==g){
			left.back().ss=mid-i;
		}else left.pb(mp(g,mid-i));
	}
	reverse(all(left));
	g = num[mid+1];
	for(int i=mid+1;i<=r;++i){
		g = gcd(g,num[i]);
		if(!right.empty() && right.back().ff==g){
			right.back().ss=i-mid-1;
		}else right.pb(mp(g,i-mid-1));
	}
	for(int i=0;i<sz(left);++i)
		for(int j=0;j<sz(right);++j){
			ret = max(gcd(left[i].ff, right[j].ff)*(left[i].ss+right[j].ss+2),ret);
		}
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		num = vector<lld>();
		scanf("%d",&N);
		int i,j,k;
		for(i=0;i<N;++i){
			lld x;
			scanf("%lld",&x);
			num.pb(x);
		}
		printf("%lld\n",process(0,N-1));
	}
		
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
