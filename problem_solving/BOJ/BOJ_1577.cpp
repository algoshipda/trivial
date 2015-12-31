#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n,m,k;
lld dp[105][105];
int h[105][105];
int v[105][105];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;++i){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2 || x1==x2 && y1>y2){
            swap(x1,x2);
            swap(y1,y2);
        }
        if(x1<x2){
            h[x1][y1] = 1;
        }else{
            v[x1][y1] = 1;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(!v[i][j] && j<m){
                dp[i][j+1]+=dp[i][j];
            }
            if(!h[i][j] && i<n){
                dp[i+1][j]+=dp[i][j];
            }
        }
    }
    printf("%lld\n",dp[n][m]);
}
