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


char good[30];
char str[1505];
int trie[2500000][26];
int cnt[2500000];
int chk[2500000];
int K;
int root = 0;
int sz;
int nodcnt;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%s",str);
	scanf("%s",good);
	scanf("%d",&K);
	int i,j,k;
	memset(trie,-1,sizeof(trie));
	sz = strlen(str);
	for(i=0;i<sz;++i){
		int now = root;
		int badcnt = 0;	
		for(j=i;j<sz;++j){
			int c = str[j]-'a';
			if(trie[now][c]==-1)trie[now][c] = ++nodcnt;
			now = trie[now][c];
			if(good[c]=='0')++badcnt;
			if(badcnt>K)chk[now]=1;
		}
	}
	int ans = 0;
	for(i=1;i<=nodcnt;++i)ans += !chk[i];
	printf("%d\n",ans);
		
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
