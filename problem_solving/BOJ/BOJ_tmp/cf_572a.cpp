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

int N,M;
int P,Q;
vector<int> A;
vector<int> B;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&N,&M,&P,&Q);
	int i,j,k;
	for(i=0;i<N;++i){
		int x;
		scanf("%d",&x);
		if(i<P)A.pb(x);
	}
	for(i=0;i<M;++i){
		int x;
		scanf("%d",&x);
		if(M-i<=Q)B.pb(x);
	}
	puts(A.back()<B[0]?"YES":"NO");
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
