#include <bits/stdc++.h>
using namespace std;
int chk[1050];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int a, b, x;
		scanf("%d%d",&a,&b);
		memset(chk,0,sizeof(chk));
		printf("%d.",a/b);
		a%=b;
		x=a;
		chk[a]=1;
		while(true){
			a*=10;
			a%=b;
			if(chk[a])break;
			chk[a]=1;
		}
		while(true){
			if(x==a)break;
			x*=10;
			printf("%d",x/b);
			x%=b;
		}
		printf("(");
		x*=10;
		printf("%d",x/b);
		x%=b;
		while(true){
			if(x==a)break;
			x*=10;
			printf("%d",x/b);
			x%=b;
		}
		puts(")");
	}
}
