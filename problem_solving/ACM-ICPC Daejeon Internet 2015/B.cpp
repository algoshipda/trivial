#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int a[1005];
int psum[1005];
int process(int l, int r)
{
	if(l==r)return psum[l]-psum[l-1];
	int& ret = dp[l][r];
	if(ret)return ret;
	return ret = max(a[l]+psum[r]-psum[l]-process(l+1,r),a[r]+psum[r-1]-psum[l-1]-process(l,r-1));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			psum[i]=a[i]+psum[i-1];
		}
		memset(dp,0,sizeof(dp));
		printf("%d\n",process(1,n));
	}
}