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
const int MOD = 1000000009;

string P[] = {"ABCBC","ABABC"};
int C;
struct Node{
	int t;
	int idx;
	Node* f;
	Node* nxt[26];
	Node():t(0),idx(0),f(0){for(int i=0;i<26;++i)nxt[i]=0;}
};

Node nodes[15];
Node* new_node()
{
	Node* ret = &nodes[C];
	ret->f = 0;
	ret->t = 0;
	ret->idx = C;
	C++;
	for(int i=0;i<26;++i)ret->nxt[i]=0;
	return ret;
}
int N,K;

int dp[1000005][10];
int nxtnod[10][27];
int t[27];

int rec(int len, int state)
{
    if(t[state])return 0;
    if(len==0)return 1;
    
    int& ret = dp[len][state];
    if(ret!=-1) return ret;
    ret = 0;
    for(int j=0;j<K;++j)
        ret = (ret + rec(len-1, nxtnod[state][j]))%MOD;
        
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&N,&K);
	int i,j,k;
	memset(dp,-1,sizeof(dp));
	Node* root = new_node();
	for(i=0;i<2;++i){
		Node* now = root;
		for(j=0;j<sz(P[i]);++j){
			int c = P[i][j]-'A';
			if(!now->nxt[c])now->nxt[c] = new_node();
			now = now->nxt[c];
		}
		now->t = 1;
	}

	queue<Node*> q;
	root->f = root;
	for(i=0;i<26;++i){
		if(root->nxt[i]){
			root->nxt[i]->f = root;
			q.push(root->nxt[i]);
		}
	}

	while(!q.empty()){
		Node* now = q.front();
		q.pop();
		for(i=0;i<26;++i){
			if(!now->nxt[i])continue;
			Node* tmp = now->f;
			while(tmp!=root && !tmp->nxt[i])tmp = tmp->f;
			if(tmp->nxt[i])tmp = tmp->nxt[i];
			now->nxt[i]->t |= tmp->t;
			now->nxt[i]->f = tmp;
			q.push(now->nxt[i]);
		}
	}


	for(i=0;i<C;++i){
		for(j=0;j<26;++j){
			Node* now = &nodes[i];
			while(now != root && !now->nxt[j])now = now->f;
			if(now->nxt[j])now = now->nxt[j];
			nxtnod[i][j] = now->idx;
		}
	}
	for(i=0;i<C;++i)t[i] = nodes[i].t;
	int ans = 0;
	for(i=0;i<C;++i){
		if(t[i])continue;
		ans += rec(N,i);
		ans %= MOD;
	}
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
