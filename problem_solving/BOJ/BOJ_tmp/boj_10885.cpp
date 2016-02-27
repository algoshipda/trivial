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
const int MOD = 1000000007;

int T,N;
int bcktcnt;
vector<int> bucket[100005];

int process(const vector<int>& v)
{
	if(v.empty())return 0;
	int sign = 1;
	int i,j,k;
	int acnt=0,bcnt=0;
	for(i=0;i<sz(v);++i){
		if(abs(v[i])==2)++bcnt;
		if(v[i]<0)sign^=1;
	}
	if(sign)return bcnt;
	sign = 1;

	int ret = 0;
	for(i=0;i<sz(v);++i){
		if(abs(v[i])==2)--bcnt,++acnt;
		if(v[i]<0)sign^=1;
		if(sign)ret = max(ret, acnt);
		else ret = max(ret, bcnt);
	}
	return ret;
}	

bool process2(const vector<int>& v)
{
	if(v.empty())return 0;
	int sign = 1;
	int i,j,k;
	int acnt=0,bcnt=0;
	for(i=0;i<sz(v);++i){
		if(v[i]<0)sign^=1;
		if(sign)return 1;
	}
	return 0;
}	
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int i,j,k;
	scanf("%d",&T);
	while(T--){
		for(i=0;i<=bcktcnt;++i)bucket[i].clear();
		bcktcnt = 0;
		scanf("%d",&N);
		for(i=0;i<N;++i){
			int x;
			scanf("%d",&x);
			if(x==0){
				if(!bucket[bcktcnt].empty())++bcktcnt;
				continue;
			}
			bucket[bcktcnt].pb(x);
		}
		int ans = process(bucket[0]);
		for(i=1;i<=bcktcnt;++i)ans = max(ans, process(bucket[i]));
		int res = 1;
		if(ans==0){
			bool found = false;
			for(i=0;i<=bcktcnt;++i){
				if(process2(bucket[i])){
					printf("1\n");
					found = true;
					break;
				}
			}
			if(found)continue;
			int x = bcktcnt?max(bucket[0][0],0):0;
			for(i=0;i<=bcktcnt;++i){
				for(j=0;j<sz(bucket[i]);++j)x = max(x,bucket[i][j]);
			}
			printf("%d\n",(x+MOD)%MOD);
			continue;
		}
		for(i=0;i<ans;++i){
			res<<=1;
			res%=MOD;
		}
		printf("%d\n",res);
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
