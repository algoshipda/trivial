#include <bits/stdc++.h>
using namespace std;

int n;
int dist[15][15];
vector<int> v;
vector<bool> vis;
int rec()
{
	if(v.size()==n){
		return dist[v.back()][0];		
	}

	int ret=(int)1e9;
	for(int i=1;i<n;++i){
		if(vis[i])continue;
		vis[i]=1;
		v.push_back(i);
		ret=min(ret, dist[v[v.size()-2]][i]+rec());
		vis[i]=0;
		v.pop_back();
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&dist[i][j]);
		}
	}
	vis=vector<bool>(n);
	vis[0]=1;
	v.push_back(0);
	printf("%d\n",rec());
}
