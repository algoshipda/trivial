#include <bits/stdc++.h>
using namespace std;
int inf=1e9+100;
int main()
{
	int n;
	scanf("%d",&n);

	vector<int> v(n);
	vector<int> lis(n+1,inf);
	for(int i=0;i<n;++i)scanf("%d",&v[i]);
	for(int i=0;i<n;++i)*lower_bound(lis.begin(),lis.end(),v[i])=v[i];
	printf("%d\n",lower_bound(lis.begin(),lis.end(),inf)-lis.begin());
}	
