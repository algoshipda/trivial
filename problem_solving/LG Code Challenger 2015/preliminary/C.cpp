#include <bits/stdc++.h>
using namespace std;
int adj[505][505];
bool ok[505][505];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				scanf("%d",&adj[i][j]);
				adj[j][i]=adj[i][j];
			}
		}
		memset(ok,0,sizeof(ok));
		bool valid=true;
		for(int k=1;k<=n;++k){
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					if(i==k || j==k)continue;
					if(adj[i][j]>adj[i][k]+adj[k][j]){
						valid=false;
					}
					if(adj[i][j]==adj[i][k]+adj[k][j]){
						ok[i][j]=1;
					}
				}
			}
		}
		if(!valid){
			puts("-1");
			continue;
		}
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(!ok[i][j])ans+=adj[i][j];
			}
		}
		printf("%lld\n",ans);
	}
}