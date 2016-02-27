#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iostream>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

int N;
int t[10045][33];
lld dp[10045][33];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        memset(t,0,sizeof(t));
        
        for(int i=1;i<=N;++i)
            scanf("%d%d",&t[i][0],&t[i][1]);
        
        for(int i=1;i<=N;++i)
            t[i][1]<<=1;
        
        for(int i=0;i<=N+40;++i){
            for(int j=0;j<=30;++j){
                dp[i][j] = LINF;
            }
        }
        dp[0][0] = 0;
        for(int i=0;i<N;++i){
            dp[i+1][0] = min(dp[i+1][0], min(min(dp[i][0]+6,3+dp[i][0]+t[i+1][1]),dp[i][0] + t[i+1][0] + t[i+1][1]));
            dp[i+1][7] = min(dp[i+1][7], dp[i][0] + 18);
            dp[i+1][30] = min(dp[i+1][30], dp[i][0] + 45);
            for(int j=0;j<=30;++j){
                if(j)dp[i+1][j-1] = min(dp[i+1][j-1],dp[i][j] + min(6, t[i+1][1]));
                int k = max(j-7,0);
                dp[i+7][k] = min(dp[i+7][k], 36 + dp[i][j]);
                k = max(j-30,0);
                dp[i+30][k] = min(dp[i+30][k], 90 + dp[i][j]);
            }
        }

        lld ans = LINF;
        for(int i=0;i<=30;++i){
            ans = min(ans, dp[N][i]);
        }
        printf("%lld\n",ans);
    }
}

