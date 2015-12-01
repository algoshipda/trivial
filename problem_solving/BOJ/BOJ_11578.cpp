#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a[10];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;++j){
			int y;
			scanf("%d",&y);
			a[i].push_back(y-1);
		}
	}
	vector<bool> ok(n,1);
	int ans = -1;
	for(int i=0;i<(1<<m);++i){
		vector<bool> v(n);
		int cnt = 0;
		for(int j=0;j<m;++j){
			if(i&1<<j){
				++cnt;
				for(auto k: a[j])v[k]=1;
			}
		}
		if(ok==v && (ans==-1 || ans>cnt))ans=cnt;
	}
	printf("%d\n",ans);
		
}

