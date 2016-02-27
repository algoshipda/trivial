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
int N;
int h[100005];
int main()
{
        scanf("%d",&N);
        for(int i=0;i<N;++i)scanf("%d",&h[i]);
        int ans = N;
        sort(h,h+N);
        for(int i=0;i<N;++i){
                ans = min(ans, h[i]+(N-i-1));
        }
        printf("%d\n",ans);
}

