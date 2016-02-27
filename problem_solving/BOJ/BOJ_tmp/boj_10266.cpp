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
const int DEG = 360000;
const int MOD1 = 500003;
const int MOD2 = 360007;
vector<int> A;
vector<int> B;
vector<int> Adif;
vector<int> Bdif;
int N;
lld W1;
lld W2;

int main()
{
        scanf("%d",&N);
        for(int i=0;i<N;++i){
                int a;
                scanf("%d",&a);
                A.pb(a);
        }
        for(int i=0;i<N;++i){
                int a;
                scanf("%d",&a);
                B.pb(a);
        }
        sort(A.rbegin(),A.rend());
        sort(B.rbegin(),B.rend());
        for(int i=0;i<N;++i){
                int a = A[i] - A[(i+1)%N];
                int b = B[i] - B[(i+1)%N];
                a = (a+DEG)%DEG;
                b = (b+DEG)%DEG;
                Adif.pb(a);
                Bdif.pb(b);
        }
        for(int i=0;i<N;++i){
                Bdif.pb(Bdif[i]);
        }
        W1 = W2 = 1;
        for(int i=1;i<N;++i){
                W1 = (W1*DEG)%MOD1;
                W2 = (W2*DEG)%MOD2;
        }
        
        lld srcHash1 = 0;
        lld srcHash2 = 0;
        
        for(int i=0;i<N;++i){
                srcHash1 = ((srcHash1 * DEG) + Adif[i])%MOD1;
                srcHash2 = ((srcHash2 * DEG) + Adif[i])%MOD2;
        }
        lld desHash1 = 0;
        lld desHash2 = 0;
        for(int i=0;i<N;++i){
                desHash1 = ((desHash1 * DEG) + Bdif[i])%MOD1;
                desHash2 = ((desHash2 * DEG) + Bdif[i])%MOD2;                
        }
        bool ans = false;
        for(int i=0;i+N<=(N<<1);++i){
                if(srcHash1 == desHash1 && srcHash2 == desHash2){
                        ans = true;
                        break;
                }
                if(i+N<(N<<1)){
                        desHash1 = (((desHash1 - (W1*Bdif[i]))%MOD1)+MOD1)%MOD1;
                        desHash2 = (((desHash2 - (W2*Bdif[i]))%MOD2)+MOD2)%MOD2;
                        desHash1 *= DEG;
                        desHash2 *= DEG;
                        desHash1 = (desHash1 + Bdif[i+N])%MOD1;
                        desHash2 = (desHash2 + Bdif[i+N])%MOD2;
                }
        }
        puts(ans?"possible":"impossible");
}
