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
    P(int _x = 0, int _y = 0):x(_x),y(_y){}
};

//벡터 a에 대해 벡터 b가 반시계?
int ccw(P a, P b)
{
    //외적
    lld cross = (lld)a.x*b.y - (lld)a.y*b.x;
    if(cross > 0)return 1;
    if(cross < 0)return -1;
    return 0;
}

//선분 ab에 대해 선분 ac가시 반시계? 
int ccw(P a, P b, P c)
{
    return ccw(P(b.x - a.x, b.y - a.y), P(c.x - a.x, c.y - a.y));
}


int N;
vector<P> p;


bool cmp(P a, P b)
{
    int c = ccw(p[0], a, b);
    if(c > 0)return 1;
    if(c < 0)return 0;
    if(a.x != b.x)return a.x < b.x;
    return a.y < b.y; 
}

vector<P> graham_scan()
{
    vector<P> stk;
    for(int i=0;i<(int)p.size();++i){
        //점을 최소한 3개 보존한다.
        //스택의 스택의 최상단부 바로 밑에 있는 점을 기준으로 
        //스택의 최상단부 점에서 p[i]로 시계방향 일동안 스택에서 뽑는다.
        while(stk.size()>=2 && ccw(stk[stk.size()-2],stk.back(),p[i])<=0)
            stk.pop_back();
        //점 추가
        stk.push_back(p[i]);
    }
    return stk;
}
int main()
{
    scanf("%d",&N);
    int midx = 0;//가장 왼쪽 가장 밑 (x,y) 최소인 점 인덱스
    for(int i=0;i<N;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        p.pb(P(x,y));
        
        //(x,y)가 최소인 점을 찾는다.
        if(p[i].x < p[midx].x || (p[i].x == p[midx].x && p[i].y < p[midx].y))midx = i;
    }
    
    //(x,y)가 최소인 점을 배열의 가장 앞으로 옮긴다.
    swap(p[0],p[midx]);
    
    //(x,y)가 최소인 점을 기준으로 나머지 점을 반시계방향으로 정렬한다.
    sort(p.begin()+1,p.end(),cmp);
    
    vector<P> convex_hull = graham_scan();
    printf("%d\n", (int)convex_hull.size());
    for(int i=0;i<(int)convex_hull.size();++i)printf("%d %d\n", convex_hull[i].x, convex_hull[i].y);
}

