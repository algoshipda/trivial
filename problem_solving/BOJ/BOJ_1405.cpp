#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
double p[4];
int X[20];
int Y[20];
int n;
double rec(int x, int y, int cnt)
{
	for(int i=0;i<cnt;++i)if(X[i]==x && Y[i]==y)return 0.0;
	if(cnt==n)return 1.0;
	double ret=0.0;
	for(int i=0;i<4;++i){
		X[cnt+1]=x+dx[i];
		Y[cnt+1]=y+dy[i];
		ret+=rec(X[cnt+1],Y[cnt+1],cnt+1)*p[i];
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<4;++i){
		int x;
		scanf("%d",&x);
		p[i]=(double)x/100;
	}
	printf("%.20f\n",rec(0,0,0));
}

