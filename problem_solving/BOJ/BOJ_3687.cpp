#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int cnt[]={6,2,5,5,4,5,6,3,7,6};
int dp[105][105][105];
int rec(int len, int first, int rem)
{	
	if(rem < 0) return 0;
	if(len == 1){
		return cnt[first] == rem;
	}
	int &ret = dp[len][first][rem];
	if(ret!=-1)return ret;
	ret = 0;
	for(int i=0;i<10;++i){
		ret |= rec(len-1,i,rem-cnt[first]);
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));

	while(t--){
		int x;
		scanf("%d",&x);
		int sl=-1,sx;
		for(int i=1;i<=100;++i){
			for(int j=1;j<10;++j){
				if(rec(i,j,x)){
					sl=i;
					sx=j;
					break;
				}
			}
			if(sl!=-1)break;
		}
		int rem=x;
		while(sl){
			rem-=cnt[sx];
			printf("%d",sx);
			--sl;
			for(int i=0;i<10;++i){
				if(rec(sl,i,rem)){
					sx=i;
					break;
				}
			}
		}
		printf(" ");
		sl=-1;
		for(int i=100;i>0;--i){
			for(int j=9;j>=0;--j){
				if(rec(i,j,x)){
					sl=i;
					sx=j;
					break;
				}
			}
			if(sl!=-1)break;
		}
		rem=x;
		while(sl){
			rem-=cnt[sx];
			printf("%d",sx);
			--sl;
			for(int i=9;i>=0;--i){
				if(rec(sl,i,rem)){
					sx=i;
					break;
				}
			}
		}
		puts("");
	}
}
