#include <bits/stdc++.h>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

vector<int> getPartialMatchBF(const string& N)
{
    vector<int> ret (N.size(),0);
    for(int i=1;i<(int)N.size();++i){
        int cnt = 0;
        for(int j=0;j+i<(int)N.size();++j){
            if(N[i+j]!=N[j])break;
            ++cnt;
            ret[i+j] = max(ret[i+j],cnt);
        }
    }
    return ret;
}

vector<int> getPartialMatchFast(const vector<int>& N)
{
    vector<int> ret(N.size(),0);
    
    int matched = 0;
    for(int start=1;start<(int)N.size();++start){
        while(matched>0 && N[start]!=N[matched])matched = ret[matched-1];
        if(N[start] == N[matched]){
            ++matched;
            ret[start] = matched;
        }
    }    
    return ret;
}

const int MOD = 360000;
int N;
vector<int> ta;
vector<int> tb;
vector<int> A;
vector<int> B;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        int x;
        scanf("%d",&x);
        ta.pb(x);
    }
    for(int i=0;i<N;++i){
        int x;
        scanf("%d",&x);
        tb.pb(x);
    }
    sort(ta.begin(),ta.end());
    sort(tb.begin(),tb.end());
    for(int i=0;i<N;++i){
        A.pb(((ta[(i+1)%N]-ta[i])+MOD)%MOD);
        B.pb(((tb[(i+1)%N]-tb[i])+MOD)%MOD);
    }
    for(int i=0;i<N;++i)A.pb(A[i]);
    vector<int> p = getPartialMatchFast(B);
    int matched = 0;
    bool ans = false;
    for(int i=0;i<(N<<1);++i){
        while(matched > 0 && A[i] != B[matched])matched = p[matched-1];
        if(A[i]==B[matched]){
            ++matched;
            if(matched==N){
                ans = true;
                break;
            }
        }
    }
    if(ans)puts("possible");
    else puts("impossible");
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

