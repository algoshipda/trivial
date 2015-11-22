#include <stdio.h>
int a[10005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int cur=1;
		int ans=0;
		while(cur!=n){
			cur=a[cur];
			++ans;
			if(ans>n)break;
		}
		printf("%d\n",ans>n?0:ans);
	}
}
