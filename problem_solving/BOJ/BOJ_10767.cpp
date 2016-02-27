#include <iostream>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

const int MN = 20;
int n;
char board[MN][MN];
set<string> a[MN];
set<string> b[MN];

void dfs(int cx, int cy, string& cur, int delta)
{
    if(cx < 0 || cx >= n || cy < 0 || cy >= n) return;
    cur.push_back(board[cx][cy]);
    if(cx + cy == n - 1){
        if(delta == 1){
            a[cx].insert(cur);
        }else{
            b[cx].insert(cur);
        }
        cur.pop_back();
        return;
    }

    dfs(cx + delta, cy, cur, delta);
    dfs(cx, cy + delta, cur, delta);
    cur.pop_back();
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> board[i];
    string tmp;
    dfs(0, 0, tmp, 1);
    dfs(n - 1, n - 1, tmp, -1);
    set<string> ans;
    for(int x = 0; x < n; ++x){
        for(auto it : a[x]){
            if(b[x].count(it)){
                ans.insert(it);
            }
        }
    }
    cout << ans.size() << '\n';
}
