#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	set<string> s;	
	string tmp;

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> tmp;
		s.insert(tmp);
	}

	vector<string> ans;
	for(int i = 0; i < m; ++i){
		cin >> tmp;
		if(s.count(tmp)){
			ans.push_back(tmp);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i] << endl;
	}
}
