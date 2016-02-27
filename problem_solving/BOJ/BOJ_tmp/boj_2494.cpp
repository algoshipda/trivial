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

const int INF = 987654321;;
const long long LINF = 9876543212345;

int N;
char cur[10005];
char tar[10005];
int dp[10005][10]; //left, idx
int p[10005][10];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int i,j,k;
	scanf("%d %s %s",&N,cur+1,tar+1);
	for(i=0;i<=N;++i)for(j=0;j<10;++j)dp[i][j]=INF;
	dp[0][0] = 0;
	for(i=0;i<N;++i){
		for(j=0;j<10;++j){
			int c = ((cur[i+1]-'0')+j)%10;
			int t = ((tar[i+1]-'0'));
			int l = c<=t?t-c:(t-c+10)%10;
			int r = c>=t?c-t:(c-t+10)%10;

			if(dp[i+1][(j+l)%10] >= dp[i][j]+l) {
				p[i+1][(j+l)%10] = l;
				dp[i+1][(j+l)%10] = dp[i][j]+l;
			}
			if(dp[i+1][j] >= dp[i][j]+r){
			 	p[i+1][j] = -r;
			 	dp[i+1][j] = dp[i][j]+r;
			}
		}
	}
	int cnt = 0;
	int ans = INF;
	for(i=0;i<10;++i){
		if(ans>=dp[N][i]){
			cnt = i;
			ans = dp[N][i];
		}
	}
	assert(ans!=INF);
	printf("%d\n",ans);
	vector<int> s;
	for(i=N;i>0;--i){
		bool found = false;
		//left
		s.pb(p[i][cnt]);
		if(p[i][cnt]>0){
			cnt = ((cnt-p[i][cnt])+10)%10;
		}
	}	
	reverse(all(s));
	for(i=0;i<sz(s);++i)printf("%d %d\n",i+1,s[i]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
