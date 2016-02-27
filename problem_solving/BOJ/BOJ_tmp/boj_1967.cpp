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
vector<int> children[10005];
vector<int> cost[10005];

vector<int> longest;
vector<int> height;
int process(int a)
{
	if(children[a].empty())return 0;
	vector<int> x;
	int i,j,k;
	for(i=0;i<sz(children[a]);++i)
		x.pb(cost[a][i]+process(children[a][i]));
	
	sort(x.rbegin(),x.rend());
	height[a] = x[0];
	if(x.size()>=2)
		longest[a] = x[0]+x[1];
	else
		longest[a] = x[0];

	return x[0];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<N;++i){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		children[a].pb(b);
		cost[a].pb(c);
	}

	longest = height = vector<int>(N+1,0);
	process(1);
	int ans = 0;
	for(i=1;i<=N;++i)ans = max(height[i],max(ans,longest[i]));
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
