#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int n,w;

int cost[10005][2];
int cache[10005][2];

int get_dp(int idx, int type)
{
        if (idx >=n) return 0;
        
        int& ret = cache[idx][type];
        if(ret != -1) return ret;
        if (idx == n-1 && type == 0) {
                if(cost[n-1][0] + cost[n-1][1] <= w){
                        return 1;
                }
                return 2;
        }
        if (idx == n-1 && type == 1) 
                return 1;
                
        ret = INF;
        if(type == 0){
                if(cost[idx][0] + cost[idx][1] <= w){
                        ret = min(ret, 1 + get_dp(idx+1, 0));
                }
                if(cost[idx][0] + cost[idx+1][0] <= w){
                        if(cost[idx][1] + cost[idx+1][1] <= w){
                                ret = min(ret, 2 + get_dp(idx+2,0));
                        }
                        ret = min(ret, 2 + get_dp(idx+1,1));
                }
                ret = min(ret, 1 + get_dp(idx,1));
                
        }else if(type == 1){
                if(cost[idx][1] + cost[idx+1][1] <= w){
                        if(cost[idx+1][0] + cost[idx+2][0] <= w){
                                ret = min(ret, 2 + get_dp(idx+2,1));
                        }
                        ret = min(ret, 2 + get_dp(idx+2,0));
                }
                ret = min(ret, 1 + get_dp(idx+1,0));
        }
        return ret;
}
int main()
{
        int t;
        for(scanf("%d",&t);t;--t){
                memset(cache,-1,sizeof(cache));
                memset(cost,0,sizeof(cost));
                int ans = INF;
                scanf("%d%d",&n,&w);
                for(int j=0;j<2;++j){
                        for(int i=0;i<n;++i){
                                scanf("%d",&cost[i][j]);
                        }
                }
                ans = min(ans, get_dp(0,0));
                
                int c00 = cost[0][0];
                int cn0 = cost[n-1][0];
                int c01 = cost[0][1];
                int cn1 = cost[n-1][1];
                if(n==1){
                        printf("%d\n",ans);
                        continue;
                }
                memset(cache,-1,sizeof(cache));
                if (c00 + cn0 <= w && c01 + cn1 <= w) {
                        cost[0][0] = cost[n-1][0] = cost[0][1] = cost[n-1][1] = INF;
                        ans = min(ans, get_dp(0,0) - 2);
                        cost[0][0] = c00;
                        cost[n-1][0] = cn0;
                        cost[0][1] = c01;
                        cost[n-1][1] = cn1;
                }
                
                memset(cache, -1, sizeof(cache));
                if (c00 + cn0 <= w) {
                        cost[0][0] = cost[n-1][0] = INF;
                        ans = min(ans, get_dp(0,0) - 1);
                        cost[0][0] = c00;
                        cost[n-1][0] = cn0;
                }
                
                memset(cache, -1, sizeof(cache));
                if (c01 + cn1 <= w) {
                        cost[0][1] = cost[n-1][1] = INF;
                        ans = min(ans, get_dp(0,0) - 1);
                        cost[0][1] = c01;
                        cost[n-1][1] = cn1;
                }
                printf("%d\n",ans);
        }
}
