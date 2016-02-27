#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000003;

int cache[1003][1003];

int n,k;

int get_dp(int length, int color)
{
        if(color == 0) return 1;
        if(length <= 0) return 0;
        int& ret = cache[length][color];
        if(ret!=-1)return ret;
        return ret = (get_dp(length-1,color) + get_dp(length-2,color-1)) % MOD; 
}
int main()
{
        scanf("%d%d",&n,&k);
        memset(cache,-1,sizeof(cache));
        printf("%d\n",(get_dp(n,k)-get_dp(n-4,k-2) + MOD)%MOD);
}
