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
int A[2005];
int B[2005];
int dp[2005][2005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	for(int i=1;i<=N;++i)scanf("%d",&A[i]);
    for(int i=1;i<=N;++i)scanf("%d",&B[i]);
    for(int i=0;i<=N;++i)for(int j=0;j<=N;++j)dp[i][j]=-INF;
    dp[0][0] = 0;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(A[i+1] > B[j+1])dp[i][j+1] = max(dp[i][j+1],dp[i][j] + B[j+1]);
            dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
        }
    }
    int ans = 0;
    for(int i=1;i<=N;++i)for(int j=1;j<=N;++j) ans = max(dp[i][j],ans);
    printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif}


