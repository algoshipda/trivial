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

const int MAX_N = 1000005;
const int B = 1000;
int N,M;
int A[MAX_N];
int I[MAX_N], J[MAX_N], K[MAX_N];
int nums[MAX_N];
vector<int> bucket[MAX_N/B];
void solve()
{
	for(int i=0;i<N;++i){
		bucket[i/B].pb(A[i]);
		nums[i] = A[i];
	}
	sort(nums, nums + N);
	for(int i=0;i<N/B;++i)sort(all(bucket[i]));
	for(int i=0;i<M;++i){
		int l = I[i], R = J[i] + 1, k = K[i];
		int lb = -1, ub = N - 1;
		while(ub - lb > 1){
			int mid = (lb + ub) / 2;
			int x = nums[mid];
			int tl = l, tr = r, c = 0;

			while(tl < tr && tl % B != 0) if(A[tl++] <= x) c++;
			while(tl < tr && tr % B != 0) if(A[--tr] <= x) c++;
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif

	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
