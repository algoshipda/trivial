#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n,m,k;
lld psum[305][305];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%lld",&psum[i][j]);
			psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
		}
	}
	scanf("%d",&k);
	for(int i=0;i<k;++i){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%lld\n",psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1]);
	}
		
}
