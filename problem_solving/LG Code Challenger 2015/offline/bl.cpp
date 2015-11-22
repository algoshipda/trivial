#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MOD = 1e9+7;
int n,m;
pair<int,int> s[400005];
lld f[100005];

lld fpow(lld n, lld k)
{
	if(k==0)return 1;
	if(k%2)return n*fpow(n,k-1)%MOD;
	lld half=fpow(n,k>>1);
	return half*half%MOD;
}

lld inverse(lld n)
{
	return fpow(n, MOD - 2);
}

lld comb(lld n, lld r)
{
	return f[n]*inverse(f[r]*f[n-r]%MOD)%MOD;
}

void build(int id=1, int l=0, int r=m)
{
	if(l==r){
		s[id]=make_pair(0,-l);
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	s[id]=min(s[id<<1],s[id<<1|1]);
}

void update(int pos, int id=1, int l=0, int r=m)
{
	if(l==r){
		s[id]=make_pair(1,-l);
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid){
		update(pos, id<<1, l, mid);
	}else{
		update(pos, id<<1|1, mid+1, r);
	}
	s[id]=min(s[id<<1],s[id<<1|1]);
}

pair<int,int> query(int x, int y, int id=1, int l=0, int r=m)
{
	if(y<l || r<x)return make_pair(1,1e9);
	if(x<=l && r<=y)return s[id];
	int mid=(l+r)>>1;
	return min(query(x, y, id<<1, l, mid), query(x, y, id<<1|1, mid+1, r));
}

int main()
{
	f[0]=1;
	for(int i=1;i<=100000;++i)f[i]=f[i-1]*i%MOD;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		vector<pair<int,int>> v(n);
		for(int i=0;i<n;++i)scanf("%d",&v[i].first);
		for(int i=0;i<n;++i)scanf("%d",&v[i].second);
		sort(v.rbegin(),v.rend());
		build();
		map<int,int> cnt;
		for(int i=0;i<n;++i){
			pair<int,int> q = query(1,v[i].second);
			if(q.first)continue;
			if(cnt[v[i].second])cnt[v[i].second]++;
			else cnt[v[i].second]=1;
			update(-q.second);
		}
		lld ans=1;
		int sum=0;
		for(map<int,int>::iterator it=cnt.begin();it!=cnt.end() && sum<m;it++){
			int x=it->first;
			int y=it->second;
			int k = min(y,x-sum);
			ans*=comb(x-sum,k);
			ans%=MOD;
			ans*=f[k];
			ans%=MOD;
			sum+=k;
		}
		printf("%lld\n",ans);
	}
}