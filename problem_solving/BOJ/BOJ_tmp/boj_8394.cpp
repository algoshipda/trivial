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
int dp[5][3];
int mod(int k)
{
    return (k+4)%4;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    scanf("%d",&N);
    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][2] = 2;
    for(int i=3;i<=N;++i){
        int a = dp[mod(i)][0] = dp[mod(i-2)][2];
        int b = dp[mod(i)][1] = dp[mod(i-2)][2];
        dp[mod(i)][2] = (a+b)%10;
        dp[mod(i)][2] = (a + b + dp[mod(i-1)][0])%10; 
    }
    printf("%d\n",dp[N%4][2]);





#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

