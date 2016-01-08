#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int dp[4][3][1005];
int rec(int x, int y, int k)
{
	if(x==3 && y>0) return 0;
	if(k==1) return 1;
	int& ret=dp[x][y][k];
	if(ret!=-1)return ret;
	ret=0;
	for(int i=0;i<4;++i){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(0<=nx && nx<4 && 0<=ny && ny<3){
			ret=(ret+rec(nx,ny,k-1))%1234567;
		}
	}
	return ret;
}
int main()
{	
	memset(dp,-1,sizeof(dp));
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=0;
		for(int i=0;i<4;++i){
			for(int j=0;j<3;++j){
				ans=(ans+rec(i,j,n))%1234567;
			}
		}
		printf("%d\n",ans);
	}
}
