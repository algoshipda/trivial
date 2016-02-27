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

int N,M;
int c[105][105];
int cnt[105];
int cand[105];
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=M;++i){
        int m = 0;
        int mi = 1;
        for(int j=1;j<=N;++j){
            scanf("%d",&c[i][j]);
            if(m<c[i][j]){
                m = c[i][j];
                mi = j;
            }
        }
        cand[i] = mi;
        ++cnt[mi];
    }
    int mi = 1;
    for(int i=1;i<=N;++i){
        if(cnt[i]>cnt[mi])mi=i;
    }
    printf("%d\n",mi);

}

