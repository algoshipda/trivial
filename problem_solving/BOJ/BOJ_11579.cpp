#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>> mat(n, vector<int>(n, 0));
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> mat[j][i];
			}
		}
		vector<vector<int>> des(n, vector<int>(1, 0));
		for(int i = 0; i < n; ++i){
			cin >> des[i][0];
		}
		for(int i = 0; i < n; ++i){
			mat[i].push_back(des[i][0]);
		}
		vector<int> chk(n);
		for(int i = 0; i < n; ++i){
			for(int j = n - 1; j >= 0; --j){
				if(mat[i][j] == 1){
					assert(!chk[j]);
					chk[j] = 1;
					mat[i].push_back(j);
					break;
				}
			}
		}
		sort(mat.begin(), mat.end(), [&](vector<int>& a, vector<int>& b) -> bool{
			return a.back() < b.back();
		});
		for(int i = 0; i < n; ++i){
			des[i][0] = mat[i][n];
		}
		vector<int> sol(n);
		bool valid = true;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			long long s = 0;
			for(int j = 0; j < i; ++j){
				s += sol[j] * mat[i][j];
			}
			sol[i] = des[i][0] - s;
			if(sol[i] < 0){
				valid = false;
				break;
			}
			ans += sol[i];
		}
		if(valid){
			cout << 1 << ' ' << ans << '\n';
		}else{
			cout << 0 << '\n';
		}
	}
}
