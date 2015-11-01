#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
vector<int> s;
vector<int> a;
lld w(int i)
{
	return ((lld)s[i]*s[i])*1000/((s[i]*s[i])+(a[i]*a[i]));
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		s=vector<int>(n,0);
		a=vector<int>(n,0);
		for(int i=0;i<m;++i){
			int x,y,p,q;
			scanf("%d%d%d%d",&x,&y,&p,&q);
			s[x-1]+=p;
			a[y-1]+=p;
			s[y-1]+=q;
			a[x-1]+=q;
		}
		lld minv = 2e17;
		lld maxv = 0;
		for(int i=0;i<n;++i){
			if(s[i]==0 and a[i]==0){
				minv=min(minv,0LL);
				maxv=max(maxv,0LL);
				continue;
			}
			minv=min(minv,w(i));
			maxv=max(maxv,w(i));
		}
		printf("%lld\n%lld\n",maxv,minv);
	}
}