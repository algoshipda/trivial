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

struct ANS{
	int arr[5];
	ANS(int a, int b, int c, int d, int e){
		arr[0]=a;
		arr[1]=b;
		arr[2]=c;
		arr[3]=d;
		arr[4]=e;
	}
};
int eq[10005][5];
int N,K;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&K);
		K = min(K,5);
		int i,j,k;
		memset(calced,0,sizeof(calced);
		for(i=0;i<N;++i)for(j=0;j<5;++j)scanf("%d",&eq[i][j]);
		
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
