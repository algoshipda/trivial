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

string pro = "problem";
string P;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	while(getline(cin, P)){
		int sz = sz(P);
		int i,j,k;
		vector<int> pi(sz+1,0);
		for(i=0;i<sz;++i)if(isalpha(P[i]))P[i] = tolower(P[i]);
		int matched = 0;
		bool valid = false;
		for(i=0;i<sz;++i){
			if(P[i]==pro[matched])++matched;
			else if(P[i]=='p')matched = 1;
			else matched = 0;
			if(matched==7){
				valid = true;
				break;
			}		
		}
		puts(valid?"yes":"no");
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
