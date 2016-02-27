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
	int T;
	scanf("%d",&T);
	while(T--){
		int w[3],h[3];
		int i,j,k;
		for(i=0;i<3;++i)scanf("%d%d",&w[i],&h[i]);
		int ans = INF;
		for(i=0;i<3;++i){
			for(j=0;j<2;++j){
				ans = min(ans, max(w[i%3],w[(i+1)%3]+w[(i+2)%3]) * (h[i%3]+max(h[(i+1)%3],h[(i+2)%3])));
				ans = min(ans, max(w[i%3],max(w[(i+1)%3],w[(i+2)%3])) * (h[i%3]+h[(i+1)%3]+h[(i+2)%3]));
				swap(w[(i+1)%3],h[(i+1)%3]);
				ans = min(ans, max(w[i%3],w[(i+1)%3]+w[(i+2)%3]) * (h[i%3]+max(h[(i+1)%3],h[(i+2)%3])));
				ans = min(ans, max(w[i%3],max(w[(i+1)%3],w[(i+2)%3])) * (h[i%3]+h[(i+1)%3]+h[(i+2)%3]));				
				swap(w[(i+2)%3],h[(i+2)%3]);
				ans = min(ans, max(w[i%3],w[(i+1)%3]+w[(i+2)%3]) * (h[i%3]+max(h[(i+1)%3],h[(i+2)%3])));	
				ans = min(ans, max(w[i%3],max(w[(i+1)%3],w[(i+2)%3])) * (h[i%3]+h[(i+1)%3]+h[(i+2)%3]));
				swap(w[(i+1)%3],h[(i+1)%3]);
				ans = min(ans, max(w[i%3],w[(i+1)%3]+w[(i+2)%3]) * (h[i%3]+max(h[(i+1)%3],h[(i+2)%3])));
				ans = min(ans, max(w[i%3],max(w[(i+1)%3],w[(i+2)%3])) * (h[i%3]+h[(i+1)%3]+h[(i+2)%3]));
				swap(w[(i+2)%3],h[(i+2)%3]);
				swap(w[i%3],h[i%3]);
			}
		}
		printf("%d\n",ans);
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
