//huynsukoh
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

struct Node{
    int l;
    int r;
    int cnt;
    int m;
    char c;
    Node(){
        l=r=cnt=m=c=0;
    }
    Node(int _l, int _r, int _cnt, int _m, char _c):l(_l),r(_r),cnt(_cnt),m(_m),c(_c){}
};

struct Tree{
    vector<Node> t;
    int f;
    Tree(int _size, int _f){
        f = _f;
        t = vector<Node>(4*_size);
        
    }
};


int N,M;
int first;


int update(Tree& tr, int pos, char k)
{
    pos += first;
    tr.t[pos].c = k;
    tr.t[pos].l = tr.t[pos].r = k=='.';
    pos>>=1;
    while(pos>=1){
        Node& left = tr.t[pos<<1];
        Node& right = tr.t[pos<<1|1];
        Node& cur = tr.t[pos];
        cur.l = left.l;
        cur.r = right.r;
        if(left.m==left.l){
            cur.l += right.l;
        }
        if(right.m==right.r){
            cur.r += left.r;
        }
        cur.cnt = left.cnt + right.cnt;
        if(left.r && right.l){
            cur.cnt++;
        }
        pos>>=1;
    }

    return tr.t[1].cnt;
}

int main()
{
    scanf("%d%d",&N,&M);
    for(first=1;first<N;first<<=1);
    Tree tr(N,first);
    
    for(int i=0;i<N;++i){
        scanf(" %c",&tr.t[first+i].c);
        tr.t[first+i].l = tr.t[first+i].r = tr.t[first+i].c=='.';
        tr.t[first+i].m = 1;
    }
    
    for(int i=first-1;i>=1;--i){
        Node& left = tr.t[i<<1];
        Node& right = tr.t[i<<1|1];
        Node& cur = tr.t[i];
        cur.m = left.m<<1;
        cur.l = left.l;
        cur.r = right.r;
        if(left.m==left.l){
            cur.l += right.l;
        }
        if(right.m==right.r){
            cur.r += left.r;
        }
        cur.cnt = left.cnt + right.cnt;
        if(left.r && right.l){
            cur.cnt++;
        }
    }

    for(int i=0;i<M;++i){
        int a;
        char b;
        scanf("%d %c",&a,&b);
        printf("%d\n",update(tr,a-1,b));
    }
}

