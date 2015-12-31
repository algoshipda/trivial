#include <cstdio>
#include <map>
using namespace std;
typedef long long lld;
lld n,p,q;

map<lld, lld> dp;
lld rec(lld x)
{
	if(x == 0) return 1;
	if(dp[x])return dp[x];
	return dp[x] = rec(x/p)+rec(x/q);
}

int main()
{
	scanf("%lld%lld%lld",&n,&p,&q);
	printf("%lld\n",rec(n));
}
