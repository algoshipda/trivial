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
const int DAY = 24 * 60;
int N;
char t[100];
int localt;

int gettime(char* t)
{	
	int curtime = 0;
	bool half = false;
	bool plus = t[3]=='+';
	int i;
	for(i=4;t[i];++i){
		if(t[i]=='.'){
			if(t[i+1]=='5')half = true;
			break;
		}
		curtime *= 10;
		curtime += t[i]-'0';
	}
	return (curtime * 60 + (half?30:0))*(plus?1:-1);
}

int mod(int a)
{
	return ((a%DAY)+DAY)%DAY;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	int i,j,k,a,b;
	scanf("%d",&N);
	scanf("%d:%d ",&a,&b);
	localt = a * 60 + b;
	scanf(" %s ",t);
	localt -= gettime(t);
	localt = mod(localt);
	for(i=0;i<N;++i){
		scanf(" %s ",t);
		int curt = mod(localt+gettime(t));
		printf("%02d:%02d\n",curt/60,curt%60);
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
