#include <bits/stdc++.h>
using namespace std;


string a;
string s[2];

int dp[35][105][2];
int n;

int rec(int len, int cur, int t)
{
    if(a[len - 1] != s[t][cur]) return 0;
    if(len == a.size()) return 1;
    int& ret = dp[len][cur][t];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = cur + 1; i < n; ++i){
        ret += rec(len + 1, i, t ^ 1);
    }   
    return ret;
}
int main()
{
    cin>>a>>s[0]>>s[1];
    memset(dp,-1,sizeof(dp));
    n = s[0].size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += rec(1, i, 0);
        ans += rec(1, i, 1);
    }
    printf("%d\n",ans);
}
