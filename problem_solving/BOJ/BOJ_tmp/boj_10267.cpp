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

struct Line{
    int x1,y1,x2,y2;
    Line(int _x1, int _y1, int _x2, int _y2):x1(_x1),y1(_y1),x2(_x2),y2(_y2){
    }
    
};


typedef pair<Line, Line> pl;
int N;
vector<Line> v;
vector<Line> h;
vector<pl > A;
vector<pl > B;

bool cmp1(pl a, pl b )
{
    return abs(a.first.y1-a.second.y1) < abs(b.first.y1-b.second.y1);
}
bool cmp2(pl a, pl b)
{
    return abs(a.first.x1-a.second.x1) < abs(b.first.x1-b.second.x1);
}

int dist(pl& a)
{
    if(a.first.x1 == a.first.x2){
        return abs(a.first.x1-a.second.x1);
    }
    return abs(a.first.y1-a.second.y1);
}
int main()
{
    scanf("%d",&N);    
    for(int i=0;i<N;++i){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a>c || (a==c && b>d)){
            swap(a,c);
            swap(b,d);
        }
        if(a==c){
            //horizontal
            h.pb(Line(a,b,c,d));
        }else{
            v.pb(Line(a,b,c,d));
        }
    }
    
    for(int i=0;i<(int)h.size();++i){
        for(int j=i+1;j<(int)h.size();++j){
            A.pb(mp(h[i],h[j]));
        }
    }
    for(int i=0;i<(int)v.size();++i){
        for(int j=i+1;j<(int)v.size();++j){
            B.pb(mp(v[i],v[j]));
        }
    }
    sort(A.begin(),A.end(),cmp1);
    sort(B.begin(),B.end(),cmp2);
    int l = 0;
    int r = 0;
    int ans = 0;
    for(int i=0;i<sz(B);++i){
        Line q = B[i].first;
        Line w = B[i].second;
        printf("%d %d %d %d  %d %d %d %d\n",q.x1,q.y1,q.x2,q.y2,w.x1,w.y1,w.x2,w.y2);
    }
    while(l<(int)A.size() || r<(int)B.size()){
        if(dist(A[l]) == dist(B[r])){
            int d = dist(A[l]);
            int acnt = 0;
            while(l<(int)A.size() && dist(A[l])==d){
                ++acnt;
                ++l;
            }
            int bcnt = 0;
            while(r<(int)B.size() && dist(B[r])==d){
                ++bcnt;
                ++r;
            }
            ans += acnt*bcnt;
        }else if(dist(A[l]) < dist(B[r])) ++l;
        else ++r;
    }
    printf("%d\n",ans);
}

