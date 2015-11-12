//Test : BOJ 10868
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
int n,m;
int k,l;
int a[100005];
int st[18][100005];
int main()
{   
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i){
        scanf("%d", &st[0][i]);
    }
    for(k = 0, l = 1; (l << 1) <= n; l <<= 1, ++k);
    for(int i = 1; i <= k; ++i)for(int j = 0; j < n; ++j)st[i][j] = INF;
    int x = 1;
    for(int j = 1; j <= k; ++j){
        for(int i = 0; i < n; ++i){
            if(i + x <= n) st[j][i] = min(st[j - 1][i], st[j - 1][i + x]);
        }
        x <<= 1;
    }
    for(int i = 0; i < m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        int d = y - x + 1, w = 0, q = 1;
        for(; (q << 1) <= d; q <<= 1, ++w);
        printf("%d\n", min(st[w][x - 1], st[w][y - q]));
    }
}
