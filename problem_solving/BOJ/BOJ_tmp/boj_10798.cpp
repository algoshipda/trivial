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

char str[6][26];
int sz[6];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	for(int i=1;i<=5;++i)scanf("%s",str[i]+1);
	for(int i=1;i<=5;++i)sz[i] = strlen(str[i]+1);
	for(int j=1;j<=15;++j){
		for(int i=1;i<=5;++i){
			if(j>sz[i])continue;
			printf("%c",str[i][j]);
		}
	}
	puts("");
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
