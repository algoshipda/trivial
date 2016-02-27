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
lld H[100005];
lld L[100005];
lld R[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	while(scanf("%d",&N),N){
		int i,j,k;
		for(i=0;i<N;++i)scanf("%lld",&H[i]);
		stack<lld> stk;
		for(i=0;i<N;++i){
			while(!stk.empty() && H[stk.top()]>=H[i])stk.pop();
			L[i] = stk.empty()?0:stk.top()+1;
			stk.push(i);
		}
		while(!stk.empty())stk.pop();
		for(i=N-1;i>=0;--i){
			while(!stk.empty() && H[stk.top()]>=H[i])stk.pop();
			R[i] = stk.empty()?N-1:stk.top()-1;
			stk.push(i);
		}
		lld ans = 0;
		for(i=0;i<N;++i)ans = max(ans,H[i] * (R[i]-L[i]+1));
		printf("%lld\n",ans);
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
	