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

char a[2505];
char b[55];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	gets(a);
	gets(b);
	int asz = strlen(a);
	int bsz = strlen(b);
	vector<int> pi(bsz,0);

	int begin=1,matched=0;
	for(begin=1;begin<bsz;++begin){
		while(matched>0 && b[begin]!=b[matched])matched = pi[matched-1];
		if(b[begin]==b[matched]){
			++matched;
			pi[begin] = matched;
		}
	}	
	pi[bsz-1] = 0;
	int i,j,k;
	int ans = 0;
	matched = 0;
	for(i=0;i<asz;++i){
		while(matched>0 && a[i]!=b[matched])matched = pi[matched-1];
		if(a[i]==b[matched]){
			++matched;
			if(matched==bsz)++ans;
		}
	}
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
