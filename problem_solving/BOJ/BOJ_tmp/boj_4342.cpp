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

int canWin(int a, int b)
{
    if(a<b)swap(a,b);   
    if(b == 0)return false;
    if(canWin(b, a%b)){
        if(a-b>=b)return true;
        return false;
    }
    return true;
}
int main()
{
    int A,B;
    while(scanf("%d%d",&A,&B),A!=0 && B!=0){
        if(A<B)swap(A,B);
        puts(canWin(A,B)?"A wins":"B wins");
    }
}

