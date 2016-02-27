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

lld C;
int N;


int main()
{
    scanf("%lld%d",&C,&N);
    lld entered = 0;
    int i;
    bool ans = true;
    for(i=0;i<N;++i){
        lld x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        if(x>entered)break;
        entered -= x;
        if(y>C-entered)break;
        entered += y;
        if(z && C > entered)break;

        if(i == N-1 && (y || z))ans = false;
    }
    ans = ans && i==N && entered==0;
    puts(ans?"possible":"impossible");
}

