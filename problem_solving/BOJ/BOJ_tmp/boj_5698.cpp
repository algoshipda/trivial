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


char str[5000];

vector<string> split(char* s)
{

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	while(gets(str), str[0]!='*'){
		vector<string> s = split(str);
		int i,j,k;
		bool ans = true;
		for(i=1;i<sz(s);++i){
			if(s[i]!=s[i-1]){
				ans = false
				break;
			}
		}
		puts(ans?"Y":"N");
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
