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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int n,m,i,j,k,c,h;
	string s;
	cin>>s;
	n = s.size();
	m = 26;
	vector<int> cnt(max(n,m),0);
	vector<int> x(n,0);
	vector<int> y(n,0);
	vector<int> out(n,0);	

	for(i=0;i<n;++i)x[i]=s[i]-'a';
	for(i=0;i<n;++i)cnt[x[i]]++;
	for(i=1;i<m;++i)cnt[i]+=cnt[i-1];
	for(i=n-1;i>=0;--i)out[--cnt[x[i]]]=i;

	for(h=1;h<n;h<<=1){
		k=0;
		for(i=n-h;i<n;++i)y[k++]=i;
		for(i=0;i<n;++i)if(out[i]>=h)y[k++]=out[i]-h;
		for(i=0;i<m;++i)cnt[i]=0;
		for(i=0;i<n;++i)cnt[x[y[i]]]++;
		for(i=1;i<m;++i)cnt[i]+=cnt[i-1];
		for(i=n-1;i>=0;--i)out[--cnt[x[y[i]]]]=y[i];
		swap(x,y);
		c = 0;
		x[out[0]] = 0;
		for(i=0;i<n-1;++i)
			x[out[i+1]] = out[i]+h<n && out[i+1]+h<n && y[out[i]] == y[out[i+1]] && y[out[i]+h] == y[out[i+1]+h]?c:++c;
		m=c+1;
	}

	vector<int> rank(n,0);
	vector<int> height(n,0);  // i and i-1'th suffix's lcp
	h=0;
	for(i=0;i<n;++i)rank[out[i]]=i;
	for(i=0;i<n;++i){
		if(rank[i]==0)continue;
		j = out[rank[i]-1];
		while(s[i+h]==s[j+h])++h;
		height[rank[i]] = h;
		if(h>0)--h;
	}
	for(i=0;i<n;++i)printf("%d ",out[i]+1);
	puts("");
	printf("x ");
	for(i=1;i<n;++i)printf("%d ",height[i]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}