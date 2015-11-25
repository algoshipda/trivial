#include <stdio.h>
typedef long long lld;
int mod=1e9+7;
int n,m;
lld dp[105][105][105];
int a,b,c;
int main()
{
    scanf("%d%d",&n,&m);
    if(m>=1)a=n;
    if(m>=2)b=n;
    if(m>=3)c=n;
    dp[0][0][0]=1;
    lld ans=0;
    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;++j){
            if(i+j>=n)break;
            for(int k=0;k<=c;++k){
                if(i+j+k>=n)break;
                if(i<a)dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k]*(j+k+1))%mod;
                if(j<b)dp[i][j+1][k]=(dp[i][j+1][k]+dp[i][j][k]*(i+k+1))%mod;
                if(k<c)dp[i][j][k+1]=(dp[i][j][k+1]+dp[i][j][k]*(i+j+1))%mod;
            }
        }
    }
    for(int i=0;i<=a;++i){
        for(int j=0;j<=b;++j){
            if(i+j>n)break;
            ans=(ans+dp[i][j][n-i-j])%mod;       
        }
    }
    printf("%lld\n",ans);
}
