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


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int N;
	scanf("%d",&N);
	int i,j,k;
	stack<pii> stk;
	vector<int> ans;
	for(i=1;i<=N;++i){
		int x;
		scanf("%d",&x);
		while(!stk.empty() && stk.top().first<=x)stk.pop();
		if(stk.empty())ans.pb(0);
		else ans.pb(stk.top().second);
		stk.push(mp(x,i));
	}
	for(i=0;i<N;++i)printf("%d ",ans[i]);
	printf("\n");
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

