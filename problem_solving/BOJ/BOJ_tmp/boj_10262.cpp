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

int a[4];
int b[4];
int main()
{
        for(int i=0;i<4;++i){
                scanf("%d",&a[i]);
        }
        for(int i=0;i<4;++i){
                scanf("%d",&b[i]);
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=a[0];i<=a[1];++i){
                for(int j=a[2];j<=a[3];++j){
                        for(int k=b[0];k<=b[1];++k){
                                for(int l=b[2];l<=b[3];++l){
                                        if(i+j>k+l){
                                                ++cnt1;
                                        }else if(i+j<k+l){
                                                ++cnt2;
                                        }
                                }
                        }
                }
        }
        
        if(cnt1>cnt2)puts("Gunnar");
        else if(cnt1<cnt2)puts("Emma");
        else puts("Tie");
}
