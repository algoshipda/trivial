#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
struct Cow
{
    int s, w;
    Cow(int _s = 0, int _w = 0) : s(_s), w(_w) {}
    bool operator < (const Cow& rhs) const
    {
        return w < rhs.w;
    }
};



int main()
{
    int n, a, b;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    vector<Cow> v(n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s >> v[i].w;
        if(s[0] == 'S'){
            ans += (a <= v[i].w && v[i].w <= b);
            v[i].s = 1;
        }
    }
    v.emplace_back(0, -1e9);
    v.emplace_back(0, 1e9);
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; ++i){
        if(v[i].w <= a || b <= v[i-1].w) continue;
        int m = (v[i].w - v[i-1].w);
        if(m == 1) continue;
        if(m % 2){
            int k = v[i-1].w + m / 2;
            ans += max(0, (min(k, b) - max(v[i-1].w+1, a) + 1) * v[i-1].s);
            ans += max(0, (min(v[i].w-1, b) - max(k+1, a) + 1) * v[i].s);
        }else{
            int k = v[i-1].w + m / 2 - 1;
            if(a <= k + 1 && k + 1 <= b) ans += v[i].s | v[i-1].s;
            ans += max(0, (min(k, b) - max(v[i-1].w+1, a) + 1) * v[i-1].s);
            ans += max(0, (min(v[i].w-1, b) - max(k+2, a) + 1) * v[i].s);
        }
    }
    cout << ans << '\n';
}
