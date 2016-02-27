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
    P(int _x=0, int _y=0):x(_x),y(_y){}
};
int C;


int ccw(P a, P b)
{
    lld dot = (lld)a.x*b.y-(lld)a.y*b.x;
    if(dot > 0)return 1;
    if(dot)return -1;
    return 0;
}

int ccw(P a, P b, P c)
{
    return ccw(P(b.x-a.x,b.y-a.y),P(c.x-a.x,c.y-a.y));
}


P p[200005];
P stk[200005];

bool cmp(P a, P b)
{
    int r = ccw(p[0],a,b);
    if(r>0)return 1;
    if(r<0)return 0;
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

lld dist(P a, P b)
{
    int X = a.x-b.x;
    int Y = a.y-b.y;
    return (lld)X*X+(lld)Y*Y;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&C);
        int mi = 0;
        for(int i=0;i<C;++i){
            scanf("%d%d",&p[i].x,&p[i].y);
            if(p[i].x < p[mi].x || (p[i].x == p[mi].x && p[i].y < p[mi].y))mi = i;
        }
        swap(p[mi],p[0]);
        sort(p+1,p+C,cmp);
        for(int i=0;i<min(C,3);++i)stk[i]=p[i];
        int top = min(C-1,2);
        for(int i=3;i<C;++i){
            while(top>0 && ccw(stk[top-1],stk[top],p[i])<=0)--top;
            stk[++top] = p[i];
        }
        lld ans = -1;
        int x1 = stk[0].x;
        int y1 = stk[0].y;
        int x2 = x1;
        int y2 = y1;
        int a = 0;
        for(int i=0;i<=top;++i){
            while(dist(stk[i],stk[a])<dist(stk[i],stk[(a+1)%(top+1)])){
                a = (a+1)%(top+1);
            }
            if(ans < dist(stk[i],stk[a])){
                ans = dist(stk[i],stk[a]);
                x1 = stk[i].x;
                y1 = stk[i].y;
                x2 = stk[a].x;
                y2 = stk[a].y;
            }
        }
        printf("%d %d %d %d\n",x1,y1,x2,y2);
    }
}

