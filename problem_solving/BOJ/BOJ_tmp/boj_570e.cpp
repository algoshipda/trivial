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
char board[505][505];

char a[600][505];

vector< vector<int> > dp, pdp;
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i)scanf("%s",board[i]+1);
    if(N<M){
        for(int i=1;i<=M;++i){
            for(int j=1;j<=N;++j){
                a[i+j][i]=board[j][i];
            }
}

