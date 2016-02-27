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
char str[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%s",str);
	int level=0;
	int ans=0;
	for(int i=0;str[i];++i){
		if(i && str[i-1]=='(' && str[i]==')'){
			--ans;
			--level;
			ans += level;
		}else{
			if(str[i]=='('){
				++level;
				++ans;
			}else{
				--level;
			}
		}
	}
	printf("%d\n",ans);
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
