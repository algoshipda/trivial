#include <iostream>
#include <vector>
using namespace std;

char board[55][55];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> board[i];
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(board[i][j] == '#') continue;
            if(i + 2 < n && (i == 0 || board[i-1][j] == '#') && board[i+1][j] == '.' && board[i+2][j] == '.'){
                ans.push_back(make_pair(i+1, j+1));
            }else if(j + 2 < m && (j == 0 || board[i][j-1] == '#') && board[i][j+1] == '.' && board[i][j+2] == '.'){
                ans.push_back(make_pair(i+1, j+1));
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto x : ans){
        cout << x.first << ' ' << x.second << '\n';
    }
}
