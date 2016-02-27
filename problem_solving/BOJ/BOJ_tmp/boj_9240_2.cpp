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


struct P{
    int x,y;
    P(int a=0, int b=0):x(a),y(b){}
};

int ccw(P a, P b)
{
    lld cr = (lld)a.x*b.y-(lld)a.y*b.x;
    if(cr>0)return 1;
    if(cr)return -1;
    return 0;
}

int ccw(P a, P b, P c)
{
    return ccw(P(b.x-a.x,b.y-a.y),P(c.x-a.x,c.y-a.y));
}

int C;
P p[100005];

bool cmp (P a, P b)
{
    int r = ccw(p[0],a,b);
    if(r>0)return 1;
    if(r)return 0;
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

bool mm (P a, P b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}


int main()
{
    scanf("%d",&C);
    for(int i=0;i<C;++i){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    swap(p[0],*min_element(p,p+C,mm));
    sort(p+1,p+C,cmp);
    
    vector<P> stk;
    for(int i=0;i<C;++i){
        while(stk.size()>=2 && ccw(stk[stk.size()-2],stk.back(),p[i])<=0)stk.pop_back();
        stk.pb(p[i]);
    }
    lld ans = 0;
    for(int i=0;i<sz(stk);++i){
        for(int j=i;j<sz(stk);++j){
            lld X = stk[i].x-stk[j].x;
            lld Y = stk[i].y-stk[j].y;
            ans = max(ans, X*X+Y*Y);
        }
    }
    printf("%.8f\n",sqrt(ans));
}

