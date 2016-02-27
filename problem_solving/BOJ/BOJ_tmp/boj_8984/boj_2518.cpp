#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int nf;
int k;
int n[3];
int food[103][3];
int cache[101][101][101][3];
 
int dist(int a, int b)
{
        a = (a+nf)%nf;
        b = (b+nf)%nf;
        return min(abs(b-a), nf-abs(b-a));
}
int get_dp(int a, int b, int c, int who)
{
        if(a <0 || b<0 || c<0) return INF;
        if(a == 0 && b == 0 && c == 0)
                return 0;

        int& ret = cache[a][b][c][who];
        if(ret != -1) return ret;
        ret = INF;
        if(who == 0){
                ret = min(ret, get_dp(a-1, b, c, 0) + dist(food[a-1][0], food[a][0]));
                ret = min(ret, get_dp(a-1, b, c, 1) + dist(food[b][1]-k, food[a][0]));
                ret = min(ret, get_dp(a-1, b, c, 2) + dist(food[c][2]-2*k, food[a][0]));
        }else if(who == 1){
                ret = min(ret, get_dp(a, b-1, c, 0) + dist(food[a][0]+k, food[b][1]));
                ret = min(ret, get_dp(a, b-1, c, 1) + dist(food[b-1][1], food[b][1]));
                ret = min(ret, get_dp(a, b-1, c, 2) + dist(food[c][2]-k, food[b][1]));        
        }else{
                ret = min(ret, get_dp(a, b, c-1, 0) + dist(food[a][0]+2*k, food[c][2]));
                ret = min(ret, get_dp(a, b, c-1, 1) + dist(food[b][1]+k, food[c][2]));
                ret = min(ret, get_dp(a, b, c-1, 2) + dist(food[c-1][2], food[c][2]));        
        }
        return ret;
}
int main()
{
        memset(cache,-1,sizeof(cache));
        scanf("%d",&nf);
        k = nf/3;
        food[0][0] = 1;
        food[0][1] = 1 + k;
        food[0][2] = 1 + k*2;
        for(int j=0;j<3;++j){
                scanf("%d",&n[j]);
                for(int i=1;i<=n[j];++i){
                        scanf("%d",&food[i][j]);
                }
        }
        int ans = INF;
        for(int i=0;i<3;++i){
                ans = min(ans, get_dp(n[0],n[1],n[2],i));
        }
        /*for(int i=0;i<=3;++i)
        for(int j=0;j<=4;++j)
        for(int k=0;k<=4;++k)
        for(int x=0;x<3;++x)
        printf("%d %d %d %d %d\n",i,j,k,x,get_dp(i,j,k,x));*/
        printf("%d\n", ans);
}
