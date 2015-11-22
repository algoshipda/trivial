#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		map<int,int> count;
		for(int i=0;i<n;++i){
			int x;
			scanf("%d",&x);
			if(count[x])count[x]++;
			else count[x]=1;
		}
		for(int i=0;i<n;++i){
			int x;
			scanf("%d",&x);
		}
		lld ans = 1;
		for(int i=1;i<=m;++i)ans*=i;
		for(map<int,int>::reverse_iterator it=count.rbegin();it!=count.rend() && m;it++){
			int x=it->second;
			int k=min(m,x);
			m-=k;
			for(int i=1;i<=k;++i)ans/=i;
		}
		printf("%lld\n",ans);
	}
}