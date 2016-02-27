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

const int INF = 2e9;
const long long LINF = 9876543212345;


const int INF = 2e9;
struct Tree{
	int first;
	vector<int> tree;
	Tree(int n)
	{
		for(first=1;first<n;first<<=1);
		tree = vector<int>( n<<2, INF);
	}

	void update(int pos, int val)
	{
		pos += first;
		tree[pos] = val;
		while(pos>>1){
			tree[pos>>1] = min(tree[pos>>1],tree[pos]);
			pos>>=1;
		}
	}

	int query(int l, int r)
	{
		l += first;
		r += first;
		int ret = INF;
		while(l<=r){
			ret = min(ret, min(tree[l],tree[r]));
			l = (l+1)>>1;
			r = (r-1)>>1;
		}
		return ret;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    int n,k;
    scanf("%d%d",&n,&k);
    Tree m(n);
    Tree M(n);
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        m.update(i, x);
        M.update(i, -x);
    }

    for(int i=0;i<k;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        --a;
        --b;
        printf("%d %d\n", m.query(a,b), -M.query(a,b));
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

