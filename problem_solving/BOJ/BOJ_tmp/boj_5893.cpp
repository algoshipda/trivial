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

string a;
string b;
string c;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	cin>>a;
	b = ("0000") + a;

	for(int i=0;i<4;++i)a.pb('0');
	int carry = 0;
	while(!a.empty() && !b.empty()){
		int x = a.back()-'0';
		int y = b.back()-'0';
		int z = carry;
		a.pop_back();
		b.pop_back();
		c.pb((char((x+y+z)&1)+'0'));
		carry = (x+y+z)&2?1:0;
	}
	if(carry)c.pb('1');
	while(!c.empty()){
		printf("%c",c.back());
		c.pop_back();
	}
	printf("\n");
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
