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
int a[1003];
bool cmp(pii a, pii b)
{
	if(a.ss!=b.ss)return a.ss<b.ss;
	return a.ff<b.ff;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	int l = 1005;
	int r = 0;
	for(i=0;i<N;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x] = y;
	}
	int sum = 0;
	int mid = max_element(a,a+1001)-a;
	int tmp = 0;
	for(i=0;i<mid;++i){
		tmp = max(tmp,a[i]);
		sum += tmp;
	}
	sum += a[mid];
	tmp = 0;
	for(i=1001;i>mid;--i){
		tmp = max(tmp, a[i]);
		sum += tmp;
	}
	printf("%d\n",sum);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
