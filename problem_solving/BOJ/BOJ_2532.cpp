#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int d,l,r;
		scanf("%d%d%d",&d,&l,&r);
		v.push_back(make_pair(l,-r));
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	vector<int> lis(n+1,1e9+100);
	for(int i=n-1;i>=0;--i){
		*upper_bound(lis.begin(),lis.end(),-v[i].second)=-v[i].second;
	}
	printf("%d\n",lower_bound(lis.begin(),lis.end(),1e9+100)-lis.begin());
}
