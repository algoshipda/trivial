#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,1,1,0,-1,-1};
int dy[]={-1,-1,-1,0,1,1,1,0};
int n;
char board[15][15];
char str[55];
int dp[15][15][15];
bool go(int x, int y, int k)
{
	if(board[x][y]!=str[k])return 0;
	if(!str[k+1])return 1;
	int& ret=dp[x][y][k];
	if(ret!=-1)return ret;
	for(int i=0;i<8;++i){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(0<=nx && nx<5 && 0<=ny && ny<5 && go(nx,ny,k+1)) return ret=1;
	}
	return ret=0;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<5;++i) scanf("%s",board[i]);
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%s",str);
			printf("%s ",str);
			memset(dp,-1,sizeof(dp));
			bool valid=false;
			for(int j=0;j<5;++j){
				for(int k=0;k<5;++k){
					if(go(j,k,0)){
						valid=true;
						break;
					}
				}
				if(valid)break;
			}
			puts(valid?"YES":"NO");
		}
	}
}
