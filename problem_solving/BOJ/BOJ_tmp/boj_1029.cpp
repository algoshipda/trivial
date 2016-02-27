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
int n;
int cache[15][10][1<<15];
char adj[15][15];

int get_dp(int last, int cost, int state)
{
        int& ret = cache[last][cost][state];
        if(ret!=-1)return ret;
        ret = 1;
        for(int i=0;i<n;++i){
                if((state & (1<<i)) || i == last) continue;
                if(cost <= adj[last][i]-'0'){
                        ret = max(ret, 1 + get_dp(i,adj[last][i]-'0',state | (1<<i)));
                }
        }
        return ret;
}
int main()
{
        memset(cache,-1,sizeof(cache));
        scanf("%d",&n);
        for(int i=0;i<n;++i){
                scanf("%s",adj[i]);
        }

        printf("%d\n",get_dp(0,0,1));
}
