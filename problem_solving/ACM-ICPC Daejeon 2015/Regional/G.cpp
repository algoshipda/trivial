#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

double dist(const pair<int,int>& a, const pair<int,int>& b)
{
	double x=a.first-b.first;
	double y=a.second-b.second;
	return sqrt(x*x+y*y);
}
int cw(const pair<int,int>& a, const pair<int,int>& b, const pair<int,int>& c)
{
	lld d = (lld)(c.second-a.second)*(b.first-a.first)-(lld)(c.first-a.first)*(b.second-a.second);
	return d<=0; 
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		double ans=0.0;
		scanf("%d",&n);
		vector<pair<int,int>> pos(n);
		vector<pair<int,int>> v;
		for(int i=0;i<n;++i){
			scanf("%d%d",&pos[i].first,&pos[i].second);
			if(i)v.push_back(make_pair(i,-1));
		}
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			int k,d;
			scanf("%d%d",&k,&d);
			if(k){
				v.push_back(make_pair(k,d));
			}else{
				ans+=d;
			}
		}
		sort(v.rbegin(),v.rend());
		vector<pair<int,int>> stk;
		stk.push_back(pos[0]);
		double cur=0.0;
		for(int i=0;i<v.size();++i){			
			pair<int,int> p;
			if(v[i].second!=-1){
				pair<int,int> a=pos[v[i].first];
				pair<int,int> b=pos[(v[i].first+1)%n];
				if(a.first==b.first){
					p=make_pair(a.first,a.second+v[i].second*(a.second>b.second?-1:1));
				}else{
					p=make_pair(a.first-v[i].second,a.second);
				}
			}else{
				p=pos[v[i].first];
			}
			while(stk.size()>=2 && cw(stk[stk.size()-2],stk.back(),p)){
				cur-=dist(stk[stk.size()-2],stk.back());
				stk.pop_back();
			}
			stk.push_back(p);
			cur+=dist(stk[stk.size()-2],stk.back());
			if(v[i].second!=-1)ans+=cur;
		}
		printf("%.1f\n",ans);
	}
}