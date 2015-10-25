#include <bits/stdc++.h>
using namespace std;
int f[3][4]={{0,1,2,3},
             {3,2,1,0},
             {1,0,3,2}};
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int board[1005][1005];
bool chk[1005][1005];
int n;
int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        scanf("%d",&n);
        memset(chk,0,sizeof(chk));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                scanf(" %1d ",&board[i][j]);
            }
        }
        int cx=1;
        int cy=1;
        int dir=0;
        int ans=0;
        while(1<=cx && cx<=n && 1<=cy && cy<=n){
            if(board[cx][cy]!=0){
                ans+=chk[cx][cy]==0;
                chk[cx][cy]=1;
            }
            dir=f[board[cx][cy]][dir];
            cx=cx+dx[dir];
            cy=cy+dy[dir];
        }
        printf("Case #%d\n%d\n",tc,ans);
    }
}