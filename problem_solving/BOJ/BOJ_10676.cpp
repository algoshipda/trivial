#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MV = 1e4 + 10;
int dista[MV];
int distb[MV];

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    for(int i = 1; i <= 10000; ++i) dista[i] = distb[i] = 1e9;
    for(int i = 0; i < n; ++i){
        int v, d;
        cin >> v >> d;
        int chka = -1, chkb = -1;
        vector<int> num(d);
        for(int j = 0; j < d; ++j){
            cin >> num[j]; 
            if(chka == -1 && num[j] == a){
                chka = j;
            }
            if(chkb == -1 && num[j] == b){
                chkb = j;
            }
        }
        if(chka != -1){
            for(int j = chka; j < d; ++j){
                dista[num[j]] = min(dista[num[j]], v);
            }
        }
        if(chkb != -1){
            for(int j = 0; j <= chkb; ++j){
                distb[num[j]] = min(distb[num[j]], v);
            }
        }
    }
    int ans = dista[b];
    for(int i = 1; i <= 10000; ++i){
        ans = min(ans, dista[i] + distb[i]);
    }
    cout << (ans < 1e9 ? ans : -1) << '\n';
}
