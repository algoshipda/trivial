#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;
int N;
int dp[200005];

int bitCount(int x)
{
	int ret = 0;
	while(x){
		x>>=1;
		++ret;
	}
	return ret;
}
int process(int x)
{
    if(x==0)return 6;
	int& ret = dp[x];
	if(ret!=-1)return ret; 
	ret = 0;
	if((x&(x-1))==0) return ret = bitCount(x);	
	int k;
	for(k=1;(k<<1)<x;k<<=1);
	return ret = min(process(x-k)+4+process(k),process((k<<1)-x)+4+process(k<<1));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
 
	scanf("%d",&N);
	memset(dp,-1,sizeof(dp));
	int i,j,k;
	for(i=0;i<N;++i){
		int x;
		scanf("%d",&x);
		printf("%d\n",process(abs(x)));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
