#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n,k;
int a[105];
lld dp[105][25];
int main()
{
    scanf("%d",&n);
    --n;
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    scanf("%d",&k);
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=20;++j){
            if(j+a[i]<=20){
                dp[i][j+a[i]]+=dp[i-1][j];
            }
            if(i>1 && j-a[i]>=0){
                dp[i][j-a[i]]+=dp[i-1][j];
            }
        }
    }
    printf("%lld\n",dp[n][k]);
}
