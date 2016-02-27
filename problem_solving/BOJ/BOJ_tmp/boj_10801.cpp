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

int a[10];
int b[10];
int acnt;
int bcnt;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int i,j,k;
	for(i=0;i<10;++i)scanf("%d",&a[i]);
	for(i=0;i<10;++i)scanf("%d",&b[i]);
	for(i=0;i<10;++i)if(a[i]>b[i])++acnt;else if(a[i]<b[i])++bcnt;
	puts(acnt==bcnt?"D":(acnt>bcnt?"A":"B"));
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
