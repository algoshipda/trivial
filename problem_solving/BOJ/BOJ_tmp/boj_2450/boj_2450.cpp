#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
int n;
int num[100002];
int order[6][3] = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
int ncnt[4];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&num[i]);
		++ncnt[num[i]];
	}
	int cnt[4][4] = {0};
	int ans = INF;
	for(int i=0;i<6;++i){
		memset(cnt,0,sizeof(cnt));
		for(int j=1;j<=n;++j){
			if(j<=ncnt[order[i][0]]){
				if(num[j]!=order[i][0])
					++cnt[order[i][0]][num[j]];
			} else if(j<=ncnt[order[i][0]]+ncnt[order[i][1]]){
				if(num[j]!=order[i][1])
					++cnt[order[i][1]][num[j]];	
			} else {
				if(num[j]!=order[i][2])
					++cnt[order[i][2]][num[j]];
			}
		}	
		ans = min(ans, min(cnt[1][2],cnt[2][1]) + min(cnt[1][3],cnt[3][1]) + max(cnt[3][2],cnt[2][3]));
	}
	printf("%d\n",ans);
	return 0;
}
