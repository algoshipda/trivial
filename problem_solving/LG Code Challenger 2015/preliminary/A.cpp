#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int ans[10000005];
int N=10000000;
int main()
{
	int t;
	for(int i=1;i<=N;++i){
		for(int j=i;j<=N;++j){
			if((lld)i*j>N)break;
			for(int k=j;k<=N;++k){
				if((lld)i*j*k>N)break;
				lld x=(lld)i*i+(lld)j*j+(lld)k*k;
				lld xx=(lld)sqrt((double)x);
				if(x==xx*xx)ans[(lld)i*j*k]++;
			}
		}
	}
	for(int i=1;i<=N;++i)ans[i]+=ans[i-1];
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
}