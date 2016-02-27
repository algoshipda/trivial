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

int T,K,P;
int coin[102];
int cnt[102];
int dp[10004];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&T,&K);
	int i,j,k;
	for(i=0;i<K;++i)scanf("%d%d",&coin[i],&cnt[i]);
	dp[0] = 1;
	for(i=0;i<K;++i){
		for(j=T;j>=0;--j){
			int x = coin[i];
			for(k=0;k<cnt[i];++k){
				if(j-x<0)break;
				dp[j] += dp[j-x];
				x += coin[i];
			}
		}
	}
	printf("%d\n",dp[T]);
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
