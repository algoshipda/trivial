#include <iostream>
#include <algorithm>
using namespace std;

inline int dist(const pair<int,int>& a, const pair<int,int>& b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    vector<int> l(n), r(n);
    for(int i = 1; i < n; ++i){
        l[i] = l[i-1] + dist(v[i], v[i-1]);
    }
    for(int i = n - 2; i >= 0; --i){
        r[i] = r[i+1] + dist(v[i], v[i+1]);
    }
    int ans = 1e9;
    for(int i = 1; i < n - 1; ++i){
        ans = min(ans, l[i-1] + r[i+1] + dist(v[i-1], v[i+1]));
    }
    cout << ans << '\n';
}
