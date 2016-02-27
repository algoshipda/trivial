#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 20;
const int MM = 20000;
int n, m;

int dist1[MN][MN];
int dist2[MN][MN];

int ok1[MM];
int ok2[MM];

int main()
{
	cin >> n >> m;
	if(n == 1){
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 0; i < m; ++i){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a; --b;
		dist1[a][b] = c;
		dist2[a][b] = d;
	}

	for(int i = 1; i < (1 << n); i += 2){
		vector<int> path;
		if((i & 1 << (n - 1)) == 0) continue;
		for(int j = 0; j < n; ++j){
			if(i & 1 << j){
				path.push_back(j);
			}
		}
		int d1 = 0, d2 = 0;
		for(int j = 1; j < path.size(); ++j){
			if(dist1[path[j - 1]][path[j]] == 0) break;
			d1 += dist1[path[j - 1]][path[j]];
			d2 += dist2[path[j - 1]][path[j]];
			if(j == path.size() - 1){
				ok1[d1] = 1;
				ok2[d2] = 1;
			}
		}
	}

	for(int i = 1; i <= 15000; ++i){
		if(ok1[i] && ok2[i]){
			cout << i << '\n';
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}
