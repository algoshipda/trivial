#include <vector>
using namespace std;

void dfs(int cur, const vector<vector<int> >& adj, 
	vector<int>& start, vector<int>& finish, int& curtime)
{
	start[cur] = ++curtime;
	for(auto nxt : adj[cur])
		if(!start[nxt])
			dfs(nxt, adj, start, finish);
	finish[cur] = ++curtime;
}