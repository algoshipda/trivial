#include <bits/stdc++.h>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))

using namespace std;

typedef long long lld;
typedef unsigned long long ulld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

const int INF = 987654321;
const long long LINF = 9876543212345;

int N;
int x[100005];
int y[100005];
lld dp[100005][4];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

const int B = 100000;
int main()
{
        scanf("%d",&N);
        for(int i=0;i<=N;++i){
                scanf("%d%d",&x[i],&y[i]);
        }
        for(int i=0;i<4;++i){
                int X = x[1] + dx[i];
                int Y = y[1] + dy[i];
                if(X<1 || X>B || Y<1 || Y>B)continue;
                dp[1][i] = abs(X-x[0])+abs(Y-y[0]);
        }
        for(int i=2;i<=N;++i){
                for(int dir1=0;dir1<4;++dir1){                
                        int cx = x[i] + dx[dir1];
                        int cy = y[i] + dy[dir1];
                        if(cx<1 || cx>B || cy<1 || cy>B) continue;
                        dp[i][dir1] = LINF;
                        for(int dir2=0;dir2<4;++dir2){
                                int bx = x[i-1] + dx[dir2];
                                int by = y[i-1] + dy[dir2];
                                if(bx<1 || bx>B || by<1 || by>B)continue;
                                dp[i][dir1] = 
                                min(dp[i][dir1], dp[i-1][dir2] + abs(bx-cx)+abs(by-cy));
                        }
                }
        }
        lld ans = LINF;
        for(int i=0;i<4;++i){
                int nx = x[N] + dx[i];
                int ny = y[N] + dy[i];
                if(nx<1 || nx>B || ny<1 || ny>B)continue;
                ans = min(ans, dp[N][i]);
        }
        printf("%lld\n",ans);
        
}
