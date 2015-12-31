#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> lis(n+1,(int)1e9);
	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		*lower_bound(lis.begin(),lis.end(),-x)=-x;
	}
	printf("%d\n",lower_bound(lis.begin(),lis.end(),(int)1e9)-lis.begin());
}
