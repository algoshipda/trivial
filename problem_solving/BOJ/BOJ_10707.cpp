#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c,d,p;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&p);
	printf("%d\n",min(a*p,b+max(0,p-c)*d));
}
