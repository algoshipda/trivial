#include <bits/stdc++.h>
using namespace std;

int ans;
void go(int cur)
{
	if(cur==0){
		++ans;
		return;
	}
	for(int i=1;i<=min(cur,3);++i){
		go(cur-i);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		int x;
		scanf("%d",&x);
		go(x);
		printf("%d\n",ans);
	}
}
