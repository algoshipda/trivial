#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 1e9;
    for(int i = 0; i < n; ++i){
        bool ok = false;
        int v, c;
        cin >> v >> c;
        int chk = 0;
        for(int j = 0; j < c; ++j){
            int x;
            cin >> x;
            if(chk == 0 && x == a) ++chk;
            else if(chk == 1 && x == b) ++chk;
        }
        if(chk == 2) ans = min(ans, v);
    }
    cout << (ans < 1e9 ? ans : -1) << '\n';
}
