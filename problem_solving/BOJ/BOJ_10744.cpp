#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
const int MN = 755;
int n, m, w;
vector<vector<int>> idx;
vector<int> all;
vector<vector<int>> tree;
int board[MN][MN];

inline void add(int& a, int b)
{
    a += b;
    if(a >= MOD) a -= MOD;
}

inline void sub(int& a, int b)
{
    a -= b;
    if(a < 0) a += MOD;
}

int query(const vector<int>& t, int pos)
{
    int ret = 0;
    pos++;
    while(pos){
        add(ret, t[pos]);
        pos &= pos - 1;
    }
    return ret;
}

void update(vector<int>& t, int pos, int val)
{
    pos++;
    while(pos < t.size()){
        add(t[pos], val);
        pos += pos & -pos;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> w;
    idx.assign(w + 1, vector<int>());
    tree.assign(w + 1, vector<int>());
    all.assign(m + 1, 0);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> board[i][j];
            idx[board[i][j]].push_back(j);
        }
    }
    for(int i = 1; i <= w; ++i){
        sort(idx[i].begin(), idx[i].end());
        idx[i].erase(unique(idx[i].begin(), idx[i].end()), idx[i].end());
        tree[i].assign(idx[i].size() + 1, 0);
    }
    update(all, 0, 1);
    update(tree[board[0][0]], 0, 1);
    for(int i = 1; i <= n - 1; ++i){
        for(int j = m - 1; j >= 1; --j){
            if(i != n - 1 && j == m - 1) continue;
            int k = board[i][j];
            int pos = lower_bound(idx[k].begin(), idx[k].end(), j) - idx[k].begin();
            int val = query(all, j - 1);
            if(pos > 0){
                sub(val, query(tree[k], pos - 1));
            }
            if(i == n - 1 && j == m - 1){
                cout << val << '\n';
                return 0;
            }
            update(all, j, val);
            update(tree[k], pos, val);
        }
    }
}
