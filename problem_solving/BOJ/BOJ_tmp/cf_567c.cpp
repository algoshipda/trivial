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

int N,K;
map<lld,int> lcnt;
map<lld,int> rcnt;
lld x[200005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;++i){
        cin>>x[i];
        rcnt[x[i]]++;
	}
	lld ans = 0;
	for(int i=0;i<N;++i){
        rcnt[x[i]]--;
        if(x[i]%K==0)
            ans += (lld)lcnt[x[i]/K]*rcnt[x[i]*K];
        lcnt[x[i]]++;
	}
	cout<<ans;
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

