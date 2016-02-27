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

int T;
char A[100005];
char B[100005];
int a[100005];
int b[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%s %s",A,B);
		int i;
		int cnt = 0;
		int cnt2 = 0;
		for(i=0;A[i];++i){
			if(A[i]=='a')
				a[cnt++]=i;
			if(B[i]=='a')
				b[cnt2++]=i;
		}
		int ans = 0;
		for(i=0;i<cnt;++i){
			ans += abs(a[i]-b[i]);
		}
		printf("%d\n",ans);
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
