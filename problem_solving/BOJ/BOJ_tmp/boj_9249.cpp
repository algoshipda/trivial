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

string a;
string b;
string s;
bool cmp(int a, int b){return s[a] < s[b];}
vector<pii> ans;
vector<int> out;
vector<int> height;
int n;
int m;

void solve()
{
	sort(ans.rbegin(),ans.rend());
	if(ans.empty()){
		puts("0");
	}else{
		int p = ans[0].second;
		int x = ans[0].first;
		printf("%d\n",x);
		for(int i=p;i<p+x;++i){
			printf("%c",s[i]);
		}
		puts("");
	}
}
void lcp()
{
	vector<int> rank(n,0);
	height = vector<int>(n,0);
	int i,j,k,h;
	for(i=0;i<n;++i)rank[out[i]]=i;
	h=0;
	for(i=0;i<n;++i){
		if(rank[i]==0)continue;
		j = out[rank[i]-1];
		while(s[i+h]==s[j+h])++h;
		height[rank[i]] = h;
		if(h>0)--h;
	}
	for(i=1;i<n;++i){
		if(out[i-1]<sz(a) && out[i]>=sz(a) || out[i]<sz(a) && out[i-1]>=sz(a)){
			int x = height[i];
			if(x==0)continue;
			ans.pb(mp(x,out[i]));
		}
	}
}
void suffix_array()
{
	n = sz(s);
	vector<int> bckt;
	vector<int> bpos;
	vector<int> pos2bckt;
	vector<int> relabel;
	vector<int> tmp;
	bckt = bpos = pos2bckt = relabel = out = tmp = vector<int>(n,0);
	int i,j,k,c,p,h;
	for(i=0;i<n;++i)out[i] = i;
	sort(all(out),cmp);
	bckt[0] = 0;
	c = 0;
	for(i=0;i<n-1;++i)bckt[i+1] = s[out[i]] == s[out[i+1]] ? c : ++c;
	for(h=1;h<n;h<<=1){
		for(i=0;i<n;++i)pos2bckt[out[i]] = bckt[i];
		for(i=n-1;i>=0;--i)bpos[bckt[i]] = i;
		for(i=0;i<n;++i)if(out[i]>=n-h)tmp[bpos[pos2bckt[out[i]]]++] = out[i];
		for(i=0;i<n;++i)if(out[i]>=h)tmp[bpos[pos2bckt[out[i]-h]]++] = out[i]-h;
		relabel[0] = 0;
		c = 0;
		for(i=0;i<n-1;++i)
			relabel[i+1] = bckt[i]==bckt[i+1] && tmp[i]<n-h && tmp[i+1]<n-h && pos2bckt[tmp[i]+h] == pos2bckt[tmp[i+1]+h]?c:++c;
		
		swap(tmp,out);
		swap(relabel,bckt);
	}
}



int kmp(const string& a, const string& b)
{
	vector<int> pi(sz(b),0);
	int matched = 0;
	int i,j,k,begin;
	for(begin=1;begin<sz(b);++begin){
		while(matched>0 && b[begin]!=b[matched])matched = pi[matched-1];
		if(b[begin]==b[matched])++matched;
		pi[begin] = matched;
	}

	matched = 0;
	for(begin=0;begin<sz(a);++begin){
		while(matched > 0 && a[begin]!=b[matched])matched = pi[matched-1];
		if(a[begin]==b[matched])++matched;
		if(begin==sz(a)-1)return matched;
	}
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	cin>>a;
	cin>>b;
	if(a.size()<b.size())swap(a,b);
	m = kmp(a,b);
	s = a+char('a'-1)+b;
	suffix_array();
	lcp();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
