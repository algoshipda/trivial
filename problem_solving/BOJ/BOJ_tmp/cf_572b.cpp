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

int N,S;
map<int, int> buys;
map<int, int> sells;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&S);
	int i,j,k;
	for(i=0;i<N;++i){
		char a;
		int b,c;
		scanf(" %c %d %d ",&a,&b,&c);
		if(a=='B')buys[b] += c;
		else sells[b] += c;
	}
	map<int, int>::reverse_iterator bit = buys.rbegin();
	map<int, int>::reverse_iterator sit = sells.rbegin();
	for(i=0;i<N && sit!=sells.rend();++i){
		if(sz(sells)-i<=S)printf("S %d %d\n",sit->first,sit->second);
		++sit;
	}
	for(i=0;i<N && bit!=buys.rend();++i){
		if(i<S)printf("B %d %d\n",bit->first,bit->second);
		++bit;
	}

	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
