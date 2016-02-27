#include <bits/stdc++.h>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))

using namespace std;

typedef long long lld;
typedef unsigned long long ulld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

const int INF = 987654321;
const long long LINF = 9876543212345;

int N,K;
int dp[10005][1005];
vector<int> pos;
vector<int> sub;
int main()
{
        scanf("%d%d",&N,&K);
        for(int i=0;i<N;++i){
                int x;
                scanf("%d",&x);
                pos.pb(x);
        }
        sort(pos.begin(),pos.end());
        for(int i=1;i<N;++i){
                sub.pb(pos[i]-pos[i-1]);
        }
        sort(sub.rbegin(),sub.rend());
        int sum = 0;
        for(int i=0;i<(int)pos.size() && i < K-1;++i){
                sum  += sub[i];
        }
        printf("%d\n",pos[N-1]-pos[0] - sum);
}
