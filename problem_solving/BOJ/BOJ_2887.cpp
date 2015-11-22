#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int n;
vector<pair<lld,pair<int,int>>> edges;
int p[100005];

int f(int x)
{
	if(x==p[x])return x;
	return p[x]=f(p[x]);
}
lld mst()
{
	sort(edges.begin(),edges.end());
	for(int i=0;i<n;++i)p[i]=i;
	lld ret=0;
	for(int i=0;i<edges.size();++i){
		int u=f(edges[i].second.first);
		int v=f(edges[i].second.second);
		if(u==v)continue;
		ret+=edges[i].first;
		p[u]=v;
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	vector<pair<int,int>> x(n),y(n),z(n);
	for(int i=0;i<n;++i){
		scanf("%d%d%d",&x[i].first,&y[i].first,&z[i].first);
		x[i].second=y[i].second=z[i].second=i;
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	sort(z.begin(),z.end());
	for(int i=1;i<n;++i){
		edges.push_back(make_pair(x[i].first-x[i-1].first,make_pair(x[i].second,x[i-1].second)));
		edges.push_back(make_pair(y[i].first-y[i-1].first,make_pair(y[i].second,y[i-1].second)));
		edges.push_back(make_pair(z[i].first-z[i-1].first,make_pair(z[i].second,z[i-1].second)));
	}
	printf("%lld\n",mst());
}
