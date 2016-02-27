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

string s;

bool cmp(int a, int b)
{
	return s[a]<s[b];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif

	cin>>s;
	int i,j,k,h,c;
	int n = sz(s);
	vector<int> bckt;
	vector<int> pos2bckt;
	vector<int> tmp;
	vector<int> out;
	vector<int> bpos;
	vector<int> relabel;
	bckt = pos2bckt = tmp = out = bpos = relabel = vector<int>(n,0);
	for(i=0;i<n;++i)out[i]=i;
	sort(all(out),cmp);
	bckt[0] = 0;
	c = 0;
	for(i=0;i<n-1;++i) bckt[i+1] = s[out[i]] == s[out[i+1]] ? c : ++c;
	for(h=1;h<n;h<<=1){
		for(i=0;i<n;++i)pos2bckt[out[i]] = bckt[i];
		for(i=n-1;i>=0;--i)bpos[bckt[i]] = i;
		for(i=0;i<n;++i)if(out[i]>=n-h) tmp[bpos[pos2bckt[out[i]]]++] = out[i];
		for(i=0;i<n;++i)if(out[i]>=h)tmp[bpos[pos2bckt[out[i]-h]]++] = out[i]-h;

		c = 0;
		relabel[0] = 0;
		for(i=0;i<n-1;++i)
			relabel[i+1] = tmp[i]+h<n && tmp[i+1]+h<n && bckt[i]==bckt[i+1] && pos2bckt[tmp[i]+h]==pos2bckt[tmp[i+1]+h]?c:++c;
		swap(out,tmp);
		swap(relabel,bckt);
	}

	vector<int> rank(n,0);
	vector<int> height(n,0);
	for(i=0;i<n;++i)rank[out[i]]=i;
	h=0;
	for(i=0;i<n;++i){
		if(rank[i]==0)continue;
		j = out[rank[i]-1];
		while(s[i+h]==s[j+h])++h;
		height[rank[i]] = h;
		if(h>0)--h;
	}
	for(i=0;i<n;++i)printf("%d ", out[i]+1);
	printf("\nx ");
	for(i=1;i<n;++i)printf("%d ",height[i]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
