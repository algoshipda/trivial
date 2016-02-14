#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MN = 5e5 + 10;
int n, k, start;
string str;

int main()
{
	cin >> n >> k >> str;
	priority_queue<pair<int,int>> pq;

	string ans;
	int l = 0;
	int r = k;
	for(start = 0; start <= k; ++start){
		pq.push(make_pair(str[start] - '0', -start));
	}
	for(int i = 0; i < n - k; ++i){
		while(true){
			pair<int, int> t = pq.top();
			pq.pop();
			if(l <= -t.second && -t.second <= r){
				ans.push_back(t.first + '0');
				l = -t.second + 1;
				r++;
				for(; start <= r; ++start){
					pq.push(make_pair(str[start] - '0', -start));
				}
				break;
			}
		}
	}
	cout << ans << '\n';
}