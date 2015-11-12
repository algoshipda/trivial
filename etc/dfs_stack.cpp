#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start, const vector< vector<int> >& adj, vector<bool>& visited){
	stack<pair<int, int> > stk;
	stk.push({start,0});
	while(!stk.empty()){
		int cur = stk.top().first;
		int& idx = stk.top().second;
		bool go = false;
		if(idx==0) visited[cur] = 1;
		for(;idx<adj[cur].size();++idx){
			int nxt = adj[cur][idx];
			if(!visited[nxt]){
				++idx;
				stk.push({nxt,0});
				go = true;
				break;
			}
		}
		if(!go) stk.pop();
	}
}