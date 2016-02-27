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
bool reachable[200][200];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d ",&N);
	int i,j,k;
	for(i=0;i<N;++i){
		char a,b;
		scanf("%c => %c ",&a,&b);
		int c = a;
		int d = b;
		reachable[c][d] = 1;
	}
	for(k=(int)'A';k<=(int)'Z';++k)reachable[k][k]=1;
	for(k=(int)'a';k<=(int)'a';++k)reachable[k][k]=1;

	for(k=(int)'A';k<=(int)'z';++k){
		if(!isalpha(k))continue;
		for(i=(int)'A';i<=(int)'z';++i)
			for(j=(int)'A';j<=(int)'z';++j)
				reachable[i][j] = reachable[i][j] || reachable[i][k] && reachable[k][j];
	}
	int cnt = 0;
	for(i='A';i<='z';++i){
		for(j='A';j<='z';++j){
			if(i==j)continue;
			if(reachable[i][j])++cnt;
		}
	}
	printf("%d\n",cnt);
	for(i='A';i<='z';++i){
		for(j='A';j<='z';++j){
			if(i==j)continue;
			if(reachable[i][j])printf("%c => %c\n",char(i),char(j));
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
