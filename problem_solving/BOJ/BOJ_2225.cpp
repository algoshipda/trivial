#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld dp[205][205];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    dp[0][0] = 1;
    for(int i=0;i<m;++i){
        for(int j=0;j<=n;++j){
            for(int k=0;k<=n;++k){
                if(j+k>n)break;
                dp[i+1][j+k]  = (dp[i+1][j+k]+dp[i][j])%(int)1e9;
            }
        }
    }
    printf("%lld\n",dp[m][n]);
}
