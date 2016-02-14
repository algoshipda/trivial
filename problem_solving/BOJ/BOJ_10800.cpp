#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 2e5 + 10;
const int MS = 2e3 + 10;
int n, color[MN], sz[MN], all[MS];
vector<int> own[MN];
vector<int> psum[MN];
int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> color[i] >> sz[i];
		own[color[i]].push_back(sz[i]);
		psum[color[i]].push_back(sz[i]);
		all[sz[i]] += sz[i];
	}

	for(int i = 1; i <= 2000; ++i){
		all[i] += all[i - 1];
	}

	for(int i = 1; i <= n; ++i){
		sort(own[i].begin(), own[i].end());
		sort(psum[i].begin(), psum[i].end());
		for(int j = 1; j < psum[i].size(); ++j){
			psum[i][j] += psum[i][j - 1];
		}
	}

	for(int i = 0; i < n; ++i){
		int sum = all[sz[i] - 1];
		int l = lower_bound(own[color[i]].begin(), own[color[i]].end(), sz[i]) - own[color[i]].begin();
		if(l){
			sum -= psum[color[i]][l - 1];
		}
		cout << sum << '\n';
	}
}