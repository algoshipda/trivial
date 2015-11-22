#include <stdio.h>
int max(int a, int b){return a>b?a:b;}
int main()
{
	int N,m,M,T,R;
	scanf("%d%d%d%d%d",&N,&m,&M,&T,&R);
	if(m+T>M){
		puts("-1");
		return 0;
	}
	int cnt=0;
	int cur=m;
	while(N){
		if(cur+T<=M){
			cur=cur+T;
			N--;
		}else{
			cur=max(m,cur-R);
		}
		++cnt;
	}
	printf("%d\n",cnt);
}
