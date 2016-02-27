#include <iostream>
using namespace std;

const int MN = 105;
char board[MN][MN];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> board[i];
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		for(int j = 0; j < n; ++j){
			cnt += board[i][j] == 'C';
		}
		if (cnt > 1){
			ans += cnt * (cnt - 1) / 2;
		}
		cnt = 0;
		for(int j = 0; j < n; ++j){
			cnt += board[j][i] == 'C';
		}
		if (cnt > 1){
			ans += cnt * (cnt - 1) / 2;
		}
	}
	cout << ans << '\n';
}

