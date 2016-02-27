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


#define pb(a) push_back(a)
#define sz(a) ((int)a.size())

using namespace std;
const int INF = 987654321;
const long long LINF = 9876543212345;
int n,m;
int memory[105];
int cost[105];
int cache[10005][105];

int get_dp(int c, int idx)
{
        if(idx==n) return 0;
        int& ret = cache[c][idx];
        if(ret!=-1)return ret;
        ret = 0;

        if(c>=cost[idx+1])
                ret = max(ret, memory[idx+1] + get_dp(c-cost[idx+1],idx+1));
        ret = max(ret, get_dp(c,idx+1));
        return ret;
} 

int main()
{
        scanf("%d%d",&n,&m);
        memset(cache,-1,sizeof(cache));
        for(int i=0;i<n;++i){
                scanf("%d",&memory[i]);
        }
        for(int i=0;i<n;++i){
                scanf("%d",&cost[i]);
        }
        for(int i=0;;++i){
                if(get_dp(i,-1)>=m)return printf("%d\n",i);
        }
}
