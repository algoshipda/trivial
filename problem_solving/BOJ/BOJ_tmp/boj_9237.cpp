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
int tree[100005];
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;++i)scanf("%d",&tree[i]);
    sort(tree,tree+N);
    int ans = 0;
    int day = 0;
    for(int i=N-1;i>=0;--i){
        tree[i] += ++day;
    }
    printf("%d\n",*max_element(tree,tree+N)+1);
    
}

