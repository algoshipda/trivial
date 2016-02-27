#include <iostream>
#include <algorithm>
using namespace std;

const int MN = 1e5 + 10;
int cnt1[MN];
int cnt2[MN];
int main()
{
    int n;
    string a;
    cin >> n >> a;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == 'C'){
            cnt1[i + 1]++;
        }else if(a[i] == 'W'){
            cnt2[i + 1]++;
        }
    }
    for(int i = 1; i <= n; ++i){
        cnt1[i] += cnt1[i - 1];
    }
    for(int i = n; i >= 1; --i){
        cnt2[i] += cnt2[i + 1];
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        if(a[i - 1] == 'O'){
            ans += 1ll * cnt1[i - 1] * cnt2[i + 1];
        }
    }
    cout << ans << '\n';
}
