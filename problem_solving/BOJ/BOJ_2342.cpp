#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
int dp1[5][5];
int dp2[5][5];
int main()
{
    int x;
    for(int i=0;i<=4;++i)for(int j=0;j<=4;++j)dp1[i][j]=dp2[i][j]=INF;
    dp1[0][0]=0;
    while(scanf("%d",&x),x){
        for(int i=0;i<=4;++i){
            for(int j=0;j<=4;++j){
                if(!i && x!=j)dp2[x][j]=min(dp2[x][j],dp1[i][j]+2);
                else if(abs(i-x)==0 && x!=j){
                    dp2[x][j]=min(dp2[x][j],dp1[i][j]+1);
                }else if(abs(i-x)%2==1 && x!=j){
                    dp2[x][j]=min(dp2[x][j],dp1[i][j]+3);
                }else if(x!=j){
                    dp2[x][j]=min(dp2[x][j],dp1[i][j]+4);
                }
                if(!j && i!=x)dp2[i][x]=min(dp2[i][x],dp1[i][j]+2);
                else if(abs(j-x)==0 && i!=x){
                    dp2[i][x]=min(dp2[i][x],dp1[i][j]+1);
                }else if(abs(j-x)%2==1 && i!=x){
                    dp2[i][x]=min(dp2[i][x],dp1[i][j]+3);
                }else if(i!=x){
                    dp2[i][x]=min(dp2[i][x],dp1[i][j]+4);
                }
            }
        }
        swap(dp1,dp2);
        for(int i=0;i<=4;++i)for(int j=0;j<=4;++j)dp2[i][j]=INF;
    }
    int ans = INF;
    for(int i=0;i<=4;++i)for(int j=0;j<=4;++j)ans=min(ans,dp1[i][j]);
    printf("%d\n",ans);
}
