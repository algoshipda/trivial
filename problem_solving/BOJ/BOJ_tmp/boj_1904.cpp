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
int dp[1000005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	dp[0] = 1;
	for(int i=0;i<N;++i){
        dp[i+1] += dp[i];
        dp[i+2] += dp[i];
        dp[i+1] %= 15746;
        dp[i+2] %= 15746;
	}
    printf("%d\n",dp[N]);

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

