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

int N;
int tree[10005][2];
vector <int> depth[10005];
int root[10005];
int rec(int pos, int dep, int nod)
{
    int k = 1;
    if(tree[nod][0]!=-1){
        k += rec(pos, dep+1, tree[nod][0]);
    }
    depth[dep].pb(pos+k);
    if(tree[nod][1]!=-1){
        k += rec(pos+k, dep+1, tree[nod][1]);
    }
    return k;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    memset(tree,-1,sizeof(tree));
	scanf("%d",&N);
	for(int i=0;i<N;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        tree[a][0] = b;
        tree[a][1] = c;
        if(b!=-1)root[b] = -1;
        if(c!=-1)root[c] = -1;
	}
	for(int i=1;i<=N;++i)
        if(!root[i])
            rec(0,1,i);

	int ans = 1;
	int k = 1;
	for(int i=2;i<=N;++i){
        if(!depth[i].empty()){
            int x = depth[i].back()-depth[i].front()+1;
            if(x>ans){
                ans = x;
                k = i;
            }
        }
	}
	printf("%d %d", k, ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

