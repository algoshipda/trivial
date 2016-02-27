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
int a,b,c;
int w[1000005];
lld dp[1000005];
deque<lld> A;
deque<lld> B;
void push(lld mm, lld d)
{
	lld m = -2 * a * mm;
	lld c = d + a * mm * mm - b * mm;
	A.pb(m);
	B.pb(c);
	int k = sz(A);
	while(k>=3 && (lld)(B[k-1]-B[k-2]) * (A[k-3]-A[k-2]) < (lld)(B[k-2]-B[k-3]) * (A[k-2]-A[k-1])){
		A[k-2] = A.back();
		B[k-2] = B.back();
		A.pop_back();
		B.pop_back();
		--k;
	}
}

lld query(lld x)
{
	int k = sz(A);
	while(k>=2 && (lld)(B[0]-B[1] < (lld)x * (A[1]-A[0]))){
		A.pop_front();
		B.pop_front();
		--k;
	}
	return a*x*x + b*x + c + A.front()*x + B.front();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	scanf("%d%d%d",&a,&b,&c);
	for(i=1;i<=N;++i)scanf("%d",&w[i]);
	push(0,0);
    int sum = 0;
	for(i=1;i<=N;++i){
        sum += w[i];
		dp[i] = query(sum);
		push(sum,dp[i]);
	}
	printf("%lld\n",dp[N]);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
