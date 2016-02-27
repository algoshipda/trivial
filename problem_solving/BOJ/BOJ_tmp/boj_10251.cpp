#include <bits/stdc++.h>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

int M,N,L,G;
int H[102][102];
int V[102][102];
int dp[102][102][210][2];


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&M,&N,&L,&G);
        for(int i=1;i<=M;++i)for(int j=1;j<=N-1;++j)scanf("%d",&H[i][j]);
        for(int i=1;i<=M-1;++i)for(int j=1;j<=N;++j)scanf("%d",&V[i][j]);
        for(int i=0;i<=M;++i)for(int j=0;j<=N;++j)for(int k=0;k<=205;++k)dp[i][j][k][0] = dp[i][j][k][1] = INF;
        
        dp[1][1][0][0] = dp[1][1][0][1] = 0;
        for(int k=0;k<=200;++k){
            for(int i=1;i<=M;++i){
                for(int j=1;j<=N;++j){
                    if(i==1 && j==1){
                        dp[i+1][j][k][0] = min(dp[i+1][j][k][0],dp[i][j][k][0] + V[i][j]);
                        dp[i][j+1][k][1] = min(dp[i][j+1][k][1],dp[i][j][k][0] + H[i][j]);
                        continue;
                    }
                    dp[i+1][j][k][0] = min(dp[i+1][j][k][0], dp[i][j][k][0] + V[i][j]);
                    dp[i+1][j][k+1][0] = min(dp[i+1][j][k+1][0], dp[i][j][k][1] + V[i][j]);
                    dp[i][j+1][k][1] = min(dp[i][j+1][k][1], dp[i][j][k][1] + H[i][j]);
                    dp[i][j+1][k+1][1] = min(dp[i][j+1][k][1], dp[i][j][k][0] + H[i][j]);
                }
            }
        }
        
        for(int i=1;i<=200;++i){
            if(dp[M][N][i][0] <= G || dp[M][N][i][1] <= G){
                printf("%d\n",(M+N-2)*L+i);
                break;
            }
            if(i==200)puts("-1");
        }
    }


#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

