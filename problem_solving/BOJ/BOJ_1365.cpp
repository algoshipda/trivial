#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;
int main()
{
	scanf("%d",&n);
	v.resize(n);
	for(int i=0;i<n;++i)scanf("%d",&v[i]);
	vector<int> lis(n+1,1e9);
	for(int i=0;i<n;++i){
		int idx=lower_bound(lis.begin(),lis.end(),v[i])-lis.begin();
		lis[idx]=v[i];
	}
	printf("%d\n",n-(lower_bound(lis.begin(),lis.end(),1e9)-lis.begin()));
}
