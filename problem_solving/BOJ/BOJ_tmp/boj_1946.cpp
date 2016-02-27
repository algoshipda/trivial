#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iostream>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

struct Tree{
    vector<int> tree;
    int first;
    
    Tree(int _size){
        for(first=1;first<_size;first<<=1);
        tree = vector<int>(4*_size,-INF);
    }
    
    void update(int pos, int val){
        pos += first;
        tree[pos] = val;
        pos>>=1;
        while(pos>0){
            tree[pos] = max(tree[pos<<1], tree[pos<<1|1]);
            pos>>=1;
        }
    }
    
    int query(int l, int r)
    {
        l += first;
        r += first;
        int ret = -INF;
        while(l<=r){
            ret = max(ret, max(tree[l],tree[r]));
            l = (l+1)>>1;
            r = (r-1)>>1;
        }
        return ret;
    }
};
int N;
vector<pii> v;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        v.clear();
        for(int i=0;i<N;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            v.pb(mp(N-a,N-b));
        }
        sort(v.begin(),v.end());
        int ans = N;
        Tree tr(N);
        for(int i=0;i<N;++i){
            tr.update(i,v[i].second);
        }
        for(int i=0;i<N-1;++i){
            if(v[i].first < v[i+1].first && v[i].second < tr.query(i+1,N-1))--ans;
        }
        printf("%d\n",ans);
    }
}

