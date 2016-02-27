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
typedef pair<double, int> pdi;
const int INF = 987654321;
const long long LINF = 9876543212345;

priority_queue<pdi> pq;
int len[1003];
int cnt[1003];
double T;
int N;
double shortest;
int main()
{
    scanf("%lf%d",&T,&N);
    shortest = (double)INF;
    for(int i=0;i<N;++i){
        scanf("%d",&len[i]);
        pq.push(mp((double)len[i],i));
        cnt[i] = 1;
        shortest = min(shortest,(double)len[i]);
    }
    int ans = 0;
    while(true){
        pdi longest = pq.top();
        if(shortest/longest.first>=T)break;
        ++ans;
        pq.pop();
        int idx = longest.second;
        int nc = cnt[idx]+1;
        pq.push(mp((double)len[idx]/nc,idx));
        shortest = min(shortest,(double)len[idx]/nc);
        ++cnt[idx];
    }
    printf("%d\n",ans);
}

