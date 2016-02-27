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
	for(i=1;i<=N;++i){
		bool ans = true;
		for(j=1;j<=10;++j){
			int x;
			scanf("%d",&x);
			if((j-1)%5+1!=x)ans = false;

		}
		if(ans)printf("%d\n",i);
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
