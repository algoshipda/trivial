#include <bits/stdc++.h>
using namespace std;

int a,b,c;
double dp[105][105][105][3];

double pr(int x, int y, int z)
{
	return (double)x/z*y/(z-1)*2;
}
double rec(int x, int y, int z, int k)
{
	if(y==0 && z==0){
		if(k==0)return 1.0;
		return 0.0;
	}else if(x==0 && z==0){
		if(k==1)return 1.0;
		return 0.0;
	}else if(x==0 && y==0){
		if(k==2)return 1.0;
		return 0.0;
	}
	double& ret=dp[x][y][z][k];
	if(ret>-0.5)return ret;
	ret=0.0;
	int q = x*y+y*z+z*x;
	if(z && x)ret += rec(x-1,y,z,k)*z*x/q;
	if(x && y)ret += rec(x,y-1,z,k)*x*y/q;
	if(y && z)ret += rec(x,y,z-1,k)*y*z/q;
	return ret;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<=100;++i){
		for(int j=0;j<=100;++j){
			for(int k=0;k<=100;++k){
				for(int l=0;l<3;++l){
					dp[i][j][k][l]=-1.0;
				}
			}
		}
	}
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		printf("%.10f %.10f %.10f\n",rec(a,b,c,0),rec(a,b,c,1),rec(a,b,c,2));
	}
}
