#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> ans;
	int pos = 1;
	while(n){
		if(n & 1) ans.push_back(pos);
		n /= 2;
		++pos;
	}
	for(int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << ' ';

}