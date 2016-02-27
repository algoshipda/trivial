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

const int MOD = 20150523;
string A;
string B;

int dp1[100005][3][2][2];
int dp2[100005][3][2][2];

int process1(int pos, int rem, int less, int ans)
{
        if(pos == (int)A.size()){
                if(less && (ans == 1 || rem == 0)) return 1;
                return 0;
        }
        
        int& ret = dp1[pos][rem][less][ans];
        if(ret!=-1)return ret;
        ret = 0;
        for(int i=0;i<=9;++i){
                if(!less && (A[pos]-'0') < i) continue;
                int nextLess = less || (A[pos]-'0') > i;
                ret += process1(pos+1, (rem+i)%3, nextLess, ans || i==3||i==6||i==9);
                ret %= MOD;
        }
        return ret;
}
int process2(int pos, int rem, int less, int ans)
{
        if(pos == (int)B.size()){
                if(less && (ans == 1 || rem == 0)) return 1;
                return 0;
        }
        
        int& ret = dp2[pos][rem][less][ans];
        if(ret!=-1)return ret;
        ret = 0;
        for(int i=0;i<=9;++i){
                if(!less && (B[pos]-'0') < i) continue;
                int nextLess = less || (B[pos]-'0') > i;
                ret += process2 (pos+1, (rem+i)%3, nextLess, ans || i==3||i==6||i==9);
                ret %= MOD;
        }
        return ret;
}
int main()
{
        cin>>A>>B;
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        int ans1 = process1(0,0,0,0);
        int ans2 = process2(0,0,0,0);
        int last = 0;
        int rem = 0;
        for(int i=0;i<(int)B.size();++i){
                if(B[i]=='3' || B[i]=='6' || B[i]=='9'){
                        last = 1;
                        break;
                }
                rem = (rem+B[i]-'0')%3;
        }
        last = last || rem==0;
        printf("%d\n",(last+ans2-ans1+MOD)%MOD);
}
