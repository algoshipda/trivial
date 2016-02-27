<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int n;
int s[505][505];
int dp[505][505];
int rec(int x, int y)
{
    int& ret=dp[x][y];
    if(ret)return ret;
    ret = 1;
    for(int i=0;i<4;++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<nx && nx<=n && 0<ny && ny<=n && s[nx][ny]>s[x][y]){
            ret = max(ret, 1 + rec(nx,ny));
        }
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&s[i][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ans=max(ans,rec(i,j));
        }
    }
    printf("%d\n",ans);
}
=======
#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int n;
int s[505][505];
int dp[505][505];
int rec(int x, int y)
{
    int& ret=dp[x][y];
    if(ret)return ret;
    ret = 1;
    for(int i=0;i<4;++i){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<nx && nx<=n && 0<ny && ny<=n && s[nx][ny]>s[x][y]){
            ret = max(ret, 1 + rec(nx,ny));
        }
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&s[i][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ans=max(ans,rec(i,j));
        }
    }
    printf("%d\n",ans);
}
>>>>>>> 5b18d34fd3c47d6b2c01f29aa6d9f163f2723a0d
