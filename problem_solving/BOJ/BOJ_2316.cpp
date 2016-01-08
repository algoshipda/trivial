#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n,m;
int c[805][805];
int main()
{
	scanf("%d%d",&n,&m);
	c[1][n+1]=c[2][n+2]=INF;
	for(int i=3;i<=n;++i){
		c[i][i+n]=1;
	}
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		c[x+n][y]=c[y+n][x]=1;
	}
	int src=1;
	int snk=n+2;
	int ans=0;
	while(true){
		vector<int> p(n+n+1,-1);
		queue<int> q;
		p[src]=src;
		q.push(src);
		while(!q.empty() && p[snk]==-1){
			int cur=q.front();
			q.pop();
			for(int i=1;i<=2*n;++i){
				if(c[cur][i] && p[i]==-1){
					q.push(i);
					p[i]=cur;
				}
			}
		}
		if(p[snk]==-1)break;
		for(int s=snk;s!=p[s];s=p[s]){
			c[p[s]][s]--;
			c[s][p[s]]++;
		}
		++ans;
	}
	printf("%d\n",ans);
}
