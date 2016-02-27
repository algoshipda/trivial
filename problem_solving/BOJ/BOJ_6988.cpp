#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;

int dp[3005][3005][2];
int ord[1000005];
int arr[3005];

int rec(int x, int y, int len)
{
	int& ret=dp[x][y][len];
	if(ret!=-1)return ret;
	int k=arr[y]+arr[y]-arr[x];
	if(k<=1000000 && ord[k]){
		return ret=arr[x]+max(rec(y,ord[k],0),rec(y,ord[k],1));
	}
	if(len) return ret=0;
	else return ret=arr[x]+arr[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
		ord[arr[i]]=i;
	}
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j){
			ans=max(ans,rec(i,j,1));
		}
	}
	printf("%d\n",ans);
}
