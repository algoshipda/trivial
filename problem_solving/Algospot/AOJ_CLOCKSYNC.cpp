#include <bits/stdc++.h>
using namespace std;

int cnt[10]={3,4,4,5,5,4,3,5,5,5};
int con[10][5]={
	{0,1,2},
	{3,7,9,11},
	{4,10,14,15},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15},
	{3,14,15},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13}
};

const int INF=1e9;
int ans;
int state[16];

void push(int x, int c, int s)
{
	for(int i=0;i<cnt[x];++i){
		state[con[x][i]]=(((state[con[x][i]]+c*s)%12)+12)%12;
	}
}

void go(int len, int cur)
{
	if(len==10){
		bool valid=true;
		for(int i=0;i<16;++i){
			if(state[i]){
				valid=false;
				break;
			}
		}
		if(valid)ans=min(ans,cur);
		return;
	}

	for(int i=0;i<4;++i){
		push(len,i,3);
		go(len+1,cur+i);
		push(len,i,-3);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		ans=INF;
		for(int i=0;i<16;++i){
			scanf("%d",&state[i]);
		}
		go(0,0);
		printf("%d\n",ans==INF?-1:ans);
	}
}
