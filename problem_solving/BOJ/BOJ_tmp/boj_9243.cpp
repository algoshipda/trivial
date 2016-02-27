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
int a,b;
string A,B;
int main()
{
    scanf("%d",&N);
    cin>>A>>B;
    int ans = true;
    {
        for(int i=0;i<A.size();++i){
            if((A[i]==B[i])^!(N&1)){
                ans = false;
                break;
            }
        }
    }
    puts(ans?"Deletion succeeded":"Deletion failed");
}

