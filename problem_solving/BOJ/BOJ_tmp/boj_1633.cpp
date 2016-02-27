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

int dp[1005][17][17];
vector<int> A;
vector<int> B;
int N;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int a,b;
	vector<pii> v;
	while(scanf("%d %d",&a,&b)!=EOF){
		++N;
		A.pb(a);
		B.pb(b);
	}

	int i,j,k;
	for(i=0;i<N;++i){
		for(j=0;j<=15;++j){
			for(k=0;k<=15;++k){
				dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
				dp[i+1][j+1][k] = max(dp[i+1][j+1][k],dp[i][j][k] + A[i]);
				dp[i+1][j][k+1] = max(dp[i+1][j][k+1],dp[i][j][k] + B[i]);
			}
		}
	}
	printf("%d\n",dp[N][15][15]);
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
