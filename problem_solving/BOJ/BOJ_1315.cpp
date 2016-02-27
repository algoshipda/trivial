#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAX = 1005;
int n;
int x[MAXN], y[MAXN], p[MAXN];
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];
int cx[MAX], cy[MAX];
int main()
{
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; ++i){
		cin >> x[i] >> y[i] >> p[i];
		a[i] = x[i];
		b[i] = y[i];
	}
	a.push_back(1);
	b.push_back(1);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for(int i = 1; i <= 1000; ++i){
		for(int j = 0; j < a.size(); ++j){
			if(a[j] == i){
				cx[i] = j;
				break;
			}
		}
		for(int j = 0; j < b.size(); ++j){
			if(b[j] == i){
				cy[i] = j;
				break;
			}
		}
	}
	
	dp[0][0] = 1;
	for(int i = 0; i < a.size(); ++i)
		for(int j = 0; j < b.size(); ++j)
			for(int k = 0; k < n; ++k)
				if(a[i] >= x[k] || b[j] >= y[k]) pre[i][j] += p[k];	

	for(int i = 0; i < a.size(); ++i){
		for(int j = 0; j < b.size(); ++j){
			if(!dp[i][j]) continue;
			int q = pre[i][j] - a[i] - b[j] + 2;
			for(int k = 0; k < n; ++k){
				if(x[k] <= a[i] + q){
					dp[cx[x[k]]][j] = 1;
				}
				if(y[k] <= b[j] + q){
					dp[i][cy[y[k]]] = 1;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < a.size(); ++i){
		for(int j = 0; j < b.size(); ++j){
			int chk = 0;
			if(dp[i][j]){
				for(int k = 0; k < n; ++k){
					if(a[i] >= x[k] || b[j] >= y[k]) ++chk;
				}
			}
			ans = max(ans, chk);
		}
	}
	cout << ans << '\n';
}