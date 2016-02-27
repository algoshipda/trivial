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

int W,H;
char board[102][102];
bool in[102][102];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&H,&W);
	int i,j,k;
	for(i=1;i<=H;++i)scanf("%s",board[i]+1);
	for(i=1;i<=H;++i){
		bool out = true;
		for(j=1;j<=W;++j){
			if(board[i][j]=='/' || board[i][j]=='\\'){
				out ^= 1;
				in[i][j] = 1;
			}else if(!out)in[i][j] = 1;
		}
	}
	int sum = 0;
	int cnt = 0;
	for(i=1;i<=H;++i)for(j=1;j<=W;++j){
		if(board[i][j]=='/' || board[i][j]=='\\')++cnt;
		else if(in[i][j])++sum;
	}
	printf("%d\n",sum + (cnt>>1));	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
