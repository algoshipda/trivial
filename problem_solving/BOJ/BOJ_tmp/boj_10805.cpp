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

int h1,w1,w2,h2;
int dp[51][51][51][51];
int main()
{
#ifndef ONLINE_JUDGE    
    freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
	int i,j,k,a,b,c ;
	for(i=0;i<=50;++i)for(j=0;j<=50;++j)for(k=0;k<=50;++k)for(a=0;a<=50;++a)dp[i][j][k][a]=INF;
    for(i=1;i<=50;++i){
        for(j=1;j<=50;++j){
            dp[i][j][0][0] = i==j?1:INF;
            for(k=1;k<i;++k)dp[i][j][0][0] = min(dp[i][j][0][0], dp[k][j][0][0] + dp[i-k][j][0][0]);
            for(k=1;k<j;++k)dp[i][j][0][0] = min(dp[i][j][0][0], dp[i][k][0][0] + dp[i][j-k][0][0]);
        }
    }
	for(i=1;i<=h1;++i){//h1
		for(j=1;j<=w1;++j){//w1
			for(k=1;k<i;++k){//h2
				for(a=1;a<j;++a){//w2
					dp[i][j][k][a] = INF;
					for(c=1;c<j-a;++c)
						dp[i][j][k][a] = min(dp[i][j][k][a], dp[i][c][0][0] + dp[i][j-c][k][a]);
					dp[i][j][k][a] = min(dp[i][j][k][a],dp[i][j-a][0][0] + dp[i-k][a][0][0]);
					for(c=(j-a)+1;c<j;++c)
						dp[i][j][k][a] = min(dp[i][j][k][a], dp[i][c][k][c-(j-a)] + dp[i-k][j-c][0][0]);
					for(c=1;c<k;++c)
						dp[i][j][k][a] = min(dp[i][j][k][a], dp[c][j-a][0][0] + dp[i-c][j][k-c][a]);
					dp[i][j][k][a] = min(dp[i][j][k][a], dp[k][j-a][0][0] + dp[i-k][j][0][0]);
					for(c=k+1;c<i;++c)
						dp[i][j][k][a] = min(dp[i][j][k][a], dp[c][j][k][a] + dp[i-c][j][0][0]);    
				}
			}
		}
	}
    printf("%d\n",dp[h1][w1][h2][w2]);	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
