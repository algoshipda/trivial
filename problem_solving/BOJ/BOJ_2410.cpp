#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int n,k;
lld dp[1000005];
int p[32];
int main()
{
    scanf("%d",&n);
    int x = 1;
    p[0] = 1;
    for(k=1;;++k){
        if(x > n)break;
        x*=2;
        p[k] = x;
    }
    dp[0] = 1;

    for(int j=0;j<k;++j){
        for(int i=n;i>=0;--i){
            if(i<p[j])break;
            dp[i] = (dp[i] + dp[i-p[j]]) % (int)1e9;
        }
    }
    printf("%lld\n",dp[n]);
}   
