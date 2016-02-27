#include <bits/stdc++.h>
using namespace std;

int n,s,m;
int a[105];
int main()
{
	scanf("%d%d%d",&n,&s,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	vector<int> dp1(m+1);
	dp1[s] = 1;
	for(int i=0;i<n;++i){
		vector<int> dp2(m+1);
		for(int j=0;j<=m;++j){
			if(dp1[j]){
				if(j-a[i]>=0)dp2[j-a[i]]=1;
				if(j+a[i]<=m)dp2[j+a[i]]=1;
			}
		}
		swap(dp1,dp2);
	}
	int ans=-1;
	for(int i=0;i<=m;++i)if(dp1[i])ans=i;
	printf("%d\n",ans);
}
