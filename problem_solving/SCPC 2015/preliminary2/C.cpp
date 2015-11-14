#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int dp[105][105][15];
int n,m,k;
int h[105][105];

int cost(int a, int b)
{
	return abs(abs(a)-abs(b));
}
int rec(int x, int y, int z)
{
	if(x==n && y==m){
		if(z>=k)return 0;
		return INF;
	}
	if(x>n || y>m)return INF;
	int& ret=dp[x][y][min(z,k)];
	if(ret!=-1)return ret;
	ret=INF;
	if(x<n){
		ret=min(ret,cost(h[x][y],h[x+1][y])+rec(x+1,y,z+(h[x+1][y]<0)));
	}
	if(y<m){
		ret=min(ret,cost(h[x][y],h[x][y+1])+rec(x,y+1,z+(h[x][y+1]<0)));
	}
	return ret;
}
int main()
{
	setbuf(stdout, NULL);
	int T;
	int test_case;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d%d",&m,&n,&k);
		for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)scanf("%d",&h[i][j]);
		memset(dp,-1,sizeof(dp));
		printf("Case #%d\n%d\n", test_case, rec(0,0,0));
	}

	return 0;

}
