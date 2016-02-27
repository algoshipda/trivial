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
int step[120][120];
int dp[120][120][34];

void sum(int a, int b, int x, int y)
{
    for(int i=0;i<=30;++i){
        dp[a][b][i] += dp[x][y][i];
        dp[a][b][i+1] += dp[a][b][i]/10000;
        dp[a][b][i] %= 10000;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)scanf("%d",&step[i][j]);
	dp[1][1][0] = 1;
	for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(i==N && j==N)break;
            sum(i+step[i][j],j,i,j);
            sum(i,j+step[i][j],i,j);
        }
	}
	int start;
	for(start = 30;start>=0;--start){
        if(dp[N][N][start]!=0)break;
	}
	printf("%d",dp[N][N][start]);
	for(int i=start-1;i>=0;--i)printf("%04d",dp[N][N][i]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

