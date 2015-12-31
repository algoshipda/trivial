#include <bits/stdc++.h>
using namespace std;

int n,k;
int psum[50005];
int dp[4][50005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&psum[i]);
        psum[i] += psum[i-1];
    }
    scanf("%d",&k);
    for(int i=0;i<3;++i){
        for(int j=1;j<=n;++j){
            if(j+k-1<=n){
                dp[i+1][j+k]=max(dp[i+1][j+k-1],dp[i][j]+psum[j+k-1]-psum[j-1]);
            }
            if(j<=n)dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
        }   
    }
    int ans = 0;
    for(int i=1;i<=n+1;++i){
        ans=max(ans,dp[3][i]);
    }
    printf("%d\n",ans);
}
