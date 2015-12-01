#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	scanf("%d",&n);
	vector<int> a(n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	scanf("%d",&k);
	k=n/k;
	for(int i=0;i<n;i+=k){
		sort(a.begin()+i,a.begin()+i+k);
	}
	for(int i=0;i<n;++i)printf("%d ",a[i]);
}
