#include <stdio.h>
int main()
{
	long long a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	if(b<=0 && 0<=c){
		printf("%lld\n",-b/a+c/a+1);
	}else if(0<b){
		printf("%lld\n",c/a-(b-1)/a);	
	}else if(c<0){
		printf("%lld\n",-b/a-(-(c+1)/a));
	}
}
