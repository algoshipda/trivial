#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n,m;
int a[1005][1005];
int dp[1005][1005][3];

int rec(int x, int y, int d)
{
    if(x >= n || y >= m) return -INF;
    if(x == n - 1 && y == m - 1) return a[x][y];
    int& ret = dp[x][y][d];
    if(ret != -INF)return ret;
    if(d != 0) ret = max(ret, a[x][y] + rec(x, y + 1, 1));
    if(d != 1) ret = max(ret, a[x][y] + rec(x, y - 1, 0));
    ret = max(ret, a[x][y] + rec(x + 1, y, 2));
    return ret;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&a[i][j]);
            for(int k = 0; k < 3; ++k)dp[i][j][k]=-INF;
        }
    }

    printf("%d\n",max(rec(0,0,2),rec(0,0,1)));
}
