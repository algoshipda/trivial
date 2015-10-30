#include <bits/stdc++.h>
using namespace std;
int n,m,q,r;
int psum[2005][2005][55];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&m,&n,&q,&r);
		memset(psum,0,sizeof(psum));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int x;
				scanf("%d",&x);
				psum[i][j][x]=1;
				for(int k=1;k<=q;++k){
					psum[i][j][k]+=psum[i-1][j][k]+psum[i][j-1][k]-psum[i-1][j-1][k];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				int cnt=0;
				for(int k=1;k<=50;++k){
					int rx=min(i+r,n);
					int ry=min(j+r,m);
					int lx=max(i-r-1,0);
					int ly=max(j-r-1,0);
					if(psum[rx][ry][k]-psum[rx][ly][k]-psum[lx][ry][k]+psum[lx][ly][k])++cnt;
				}
				ans+=cnt;
			}
		}
		printf("%d\n",ans);
	}
}