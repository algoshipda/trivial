#include <cstdio>
#include <cstring>
#define max(a,b) (((a)>(b))?(a):(b))
int n;
int stk[100002][2];
int cache[100002][2];

int get_dp(int idx, int type)
{
        if(idx>=n) return 0;
        int& ret = cache[idx][type];
        if(ret)return ret;
        return ret = stk[idx][type] + max(get_dp(idx+1,type^1),get_dp(idx+2,type^1));
}
int main()
{
        int t;
        for(scanf("%d",&t);t;--t){
                scanf("%d",&n);
                memset(cache,0,sizeof(cache));
                for(int j=0;j<2;++j){
                        for(int i=0;i<n;++i){
                                scanf("%d", &stk[i][j]);
                        }
                }
                printf("%d\n", max(get_dp(0,0), get_dp(0,1)));
        }
}
