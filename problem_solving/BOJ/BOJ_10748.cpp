#include <iostream>
#include <algorithm>
using namespace std;

const int MN = 105;
int r, c, w;
int board[MN][MN];
int dp[MN][MN];


int main()
{
    cin >> r >> c >> w;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> board[i][j];       
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            for(int k = 1; i + k < r; ++k){
                for(int l = 1;  j + l < c; ++l){
                    if(board[i][j] != board[i + k][j + l]){
                        dp[i + k][j + l] += dp[i][j];
                        dp[i + k][j + l] %= (int)(1e9 + 7);
                    }
                }
            }
        }
    }
    cout << dp[r - 1][c - 1] << '\n';
}
