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
vector<string> v;
char tmp[55];
int overlap[16][16];
int dp[1<<16][16];
string dp2[1<<16][16];
void precalc()
{
	vector<string> s;
	sort(all(v),[](string a, string b){
		if(sz(a)!=sz(b))
			return sz(a)<sz(b);
		return a<b;
	});
	int i,j,k,x;
	for(i=0;i<N;++i){
		bool valid = true;
		for(j=i+1;j<N;++j){
			if(v[j].find(v[i])!=string::npos){
				valid = false;
				break;
			}
		}
		if(valid)s.pb(v[i]);		
	}
	v=s;
	sort(v.begin(),v.end());
	N=sz(v);
	for(i=0;i<N;++i){
		for(j=0;j<N;++j){
			if(i==j){
				continue;
			}
			for(k=0;k<sz(v[i]);++k){
				if(sz(v[i])-k > sz(v[j]))continue;	
				if(v[i].substr(k)==v[j].substr(0,sz(v[i])-k)){
					overlap[i][j] = sz(v[i])-k;
					break;
				}
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif

	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<N;++i){
		scanf("%s ",tmp);
		v.pb(tmp);
	}
	
	precalc();
	for(i=0;i<(1<<N);++i){
		for(j=0;j<N;++j){
			if(i&(1<<j))continue;
			for(k=0;k<N;++k){
				int nxt = i|(1<<j);
				dp[nxt][j] = max(dp[nxt][j], dp[i][k] + overlap[j][k]);
			}
		}
	}	
	int ans = 0;
	for(i=0;i<N;++i) ans = max(ans, dp[(1<<N)-1][i]);
	int cur = 0;
	int last = -1;
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
