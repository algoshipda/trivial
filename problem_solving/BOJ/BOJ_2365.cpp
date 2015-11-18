#include <bits/stdc++.h>
using namespace std;

int n,src,snk;
int a[55],b[55];
int c[105][105];
int sum;
int flow(int x)
{
	int f=0;
	for(int i=0;i<n;++i){
		c[src][i]=a[i];
		c[i][src]=0;
		c[i+n][snk]=b[i];
		c[snk][i+n]=0;
		for(int j=0;j<n;++j){
			c[i][j+n]=x;
			c[j+n][i]=0;
		}
	}
	while(true){
		vector<int> p(n*2+2,-1);
		queue<int> q;
		q.push(src);
		p[src]=src;
		while(!q.empty() && p[snk]==-1){
			int cur=q.front();
			q.pop();
			for(int i=0;i<n*2+2;++i){
				if(c[cur][i] && p[i]==-1){
					p[i]=cur;
					q.push(i);
				}
			}
		}
		if(p[snk]==-1)break;
		int m=1e9;
		for(int s=snk;s!=p[s];s=p[s]){
			m=min(m,c[p[s]][s]);
		}
		for(int s=snk;s!=p[s];s=p[s]){
			c[p[s]][s]-=m;
			c[s][p[s]]+=m;
		}
		f+=m;
	}
	return f==sum;
}
int main()
{
	scanf("%d",&n);
	src=n*2;
	snk=n*2+1;
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=0;i<n;++i){
		scanf("%d",&b[i]);
	}
	int l=0;
	int r=10000;
	while(l<r){
		int mid=(l+r)>>1;
		if(flow(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	flow(l);
	printf("%d\n",l);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			printf("%d ",l-c[i][n+j]);
		}
		puts("");
	}
}