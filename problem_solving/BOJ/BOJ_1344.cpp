#include <bits/stdc++.h>
using namespace std;

int prime[30]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};
double a,b;
double dp[19][19][19];

double rec(int r, int x, int y)
{
	if(r==18) return prime[x]||prime[y]?1.0:0.0;
	double& ret=dp[r][x][y];
	if(ret>-0.5)return ret;
	ret = 0.0;
	ret+=rec(r+1,x+1,y)*a*(1-b);
	ret+=rec(r+1,x,y)*(1-a)*(1-b);
	ret+=rec(r+1,x,y+1)*(1-a)*b;
	ret+=rec(r+1,x+1,y+1)*a*b;
	return ret;
}		
int main()
{
	int x, y;
	scanf("%d%d",&x,&y);
	a=(double)x/100;
	b=(double)y/100;
	for(int i=0;i<19;++i)for(int j=0;j<19;++j)for(int k=0;k<19;++k)dp[i][j][k]=-1.0;
	printf("%.20f\n",rec(0,0,0));
}
