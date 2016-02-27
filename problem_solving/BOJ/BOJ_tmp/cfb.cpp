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

int main()
{
    int M,N;
    int ans = 0;
    scanf("%d%d",&M,&N);
    if(M==1){
        printf("1\n");
        return 0;
    }
    if(M%2){
        int mid = M/2+1;
        if(mid<N){
            ans = N-1;
        }else if(mid>=N){
            ans = N+1;
        }
    }else{
        int mid = M/2;
        if(N<=mid){
            ans = N+1;
        }else{
            ans = N-1;
        }
    }
    printf("%d\n",ans);
}

