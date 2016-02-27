#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n;
int d;
int d2;
int an,bn,cn;
int a[102];
int b[102];
int c[102];
int dp[102][102][102][4];


int cost(int x, int y){
        if(x<y)
                return min(y-x,x+n-y);
        return min(x-y,y+n-x);
}

int mod(int x){
        return (x+n)%n;
}
int main(){
        scanf("%d",&n);
        d=n/3;
        d2 = d*2;
        scanf("%d",&an);
        a[0] = 1;
        b[0] = 1+d;
        c[0] = 1+d2;
        for(int i=1;i<=an;++i)
                scanf("%d",&a[i]);
        scanf("%d",&bn);
        for(int i=1;i<=bn;++i)
                scanf("%d",&b[i]);
        scanf("%d",&cn);
        for(int i=1;i<=cn;++i)
                scanf("%d",&c[i]);
        
        for(int i=0;i<=an;++i)
                for(int j=0;j<=bn;++j)
                        for(int k=0;k<=cn;++k)
                                for(int x=1;x<=3;++x)
                                        dp[i][j][k][x] = INF;
        dp[1][0][0][1] = cost(a[0],a[1]);
        dp[0][1][0][2] = cost(b[0],b[1]);
        dp[0][0][1][3] = cost(c[0],c[1]);
        for(int i=0;i<=an;++i){
                for(int j=0;j<=bn;++j){
                        for(int k=0;k<=cn;++k){
                                if(i==0 && j==0 && k==0) continue;
                                if(i-1>=0)
                                        dp[i][j][k][1] = min(dp[i][j][k][1],
                                                         min(dp[i-1][j][k][1] + cost(a[i-1],a[i]),
                                                         min(dp[i-1][j][k][2] + cost(mod(b[j]-d),a[i]),
                                                             dp[i-1][j][k][3] + cost(mod(c[k]-d2),a[i]))));
                                if(j-1>=0)
                                        dp[i][j][k][2] = min(dp[i][j][k][2],
                                                         min(dp[i][j-1][k][2] + cost(b[j-1],b[j]),
                                                         min(dp[i][j-1][k][3] + cost(mod(c[k]-d),b[j]),
                                                             dp[i][j-1][k][1] + cost(mod(a[i]-d2),b[j]))));
                                if(k-1>=0)
                                        dp[i][j][k][3] = min(dp[i][j][k][3],
                                                         min(dp[i][j][k-1][3] + cost(c[k-1],c[k]),
                                                         min(dp[i][j][k-1][1] + cost(mod(a[i]-d),c[k]),
                                                             dp[i][j][k-1][2] + cost(mod(b[j]-d2),c[k]))));
                                
                        }
                }
        }
        printf("%d\n",min(dp[an][bn][cn][1],min(dp[an][bn][cn][2],dp[an][bn][cn][3])));
}
