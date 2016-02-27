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
char g[12];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	for(i=0;i<N;++i)scanf(" %c ",&g[i]);
	vector<int> p;
	for(i=0;i<10;++i)p.pb(i);
	sort(p.rbegin(),p.rend());
	do{
		bool valid = true;
		for(i=0;i<N;++i){
			if(g[i]=='>' && p[i]<p[i+1]){
				valid =false;
				break;
			}else if(g[i]=='<' && p[i]>p[i+1]){
				valid = false;
				break;
			}
		}
		if(valid){
			for(i=0;i<N+1;++i)printf("%d",p[i]);
			puts("");
			break;
		}
	}while(prev_permutation(p.begin(),p.end()));
	sort(all(p));
	do{
		bool valid = true;
		for(i=0;i<N;++i){
			if(g[i]=='>' && p[i]<p[i+1]){
				valid =false;
				break;
			}else if(g[i]=='<' && p[i]>p[i+1]){
				valid = false;
				break;
			}
		}
		if(valid){
			for(i=0;i<N+1;++i)printf("%d",p[i]);
			puts("");
			break;
		}
	}while(next_permutation(p.begin(),p.end()));
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
