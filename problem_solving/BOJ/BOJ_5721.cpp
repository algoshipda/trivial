#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;    
    while(scanf("%d%d",&n,&m),n!=0){
		vector<int> dp(3);
        for(int i=1;i<=n;++i){
			int x;
            vector<int> dp2(m+1,0);
			scanf("%d",&x);
			dp2[1]=x;
            for(int j=2;j<=m;++j){
				scanf("%d",&x);
				dp2[j]=max(dp2[j-1],x+dp2[j-2]);
			}
			dp[i%3]=max(dp[(i+2)%3],dp2[m]+dp[(i+1)%3]);
		}
		printf("%d\n",dp[n%3]);
    }
}
