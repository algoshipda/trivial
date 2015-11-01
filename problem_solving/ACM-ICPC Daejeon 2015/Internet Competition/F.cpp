#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int INF=987654321;
int a[505];
int dp[505][505];
int psum[505];
int process(int l, int r)
{
	if(l==r)return 0;
	int& ret = dp[l][r];
	if(ret!=-1)return ret;
	ret = INF;
	int k = psum[r]-psum[l-1];
	for(int i=l;i<r;++i){
		ret=min(ret,process(l,i)+process(i+1,r)+k);
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			psum[i]=psum[i-1]+a[i];
		}
		printf("%d\n",process(1,n));
	}	
}