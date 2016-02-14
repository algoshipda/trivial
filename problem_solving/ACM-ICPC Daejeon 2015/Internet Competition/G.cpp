#include <bits/stdc++.h>
using namespace std;
int ax[100005];
int ay[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		vector< vector<int> > v(100005);
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
		}
		scanf("%d",&m);
		for(int i=0;i<100005;++i)sort(v[i].begin(),v[i].end());
		int cy=0;
		int cnt=1;
		int idx=0;
		for(int i=0;i<100005;++i){
			if(v[i].size()==0)continue;
			if(v[i].back()==cy){
				for(int j=(int)v[i].size()-1;j>=0;--j){
					ax[cnt]=i;
					ay[cnt]=v[i][j];
					++cnt;
				}
				cy=v[i][0];
			}else{
				for(int j=0;j<v[i].size();++j){
					ax[cnt]=i;
					ay[cnt]=v[i][j];
					++cnt;
				}
				cy=v[i].back();
			}
		}
		for(int i=0;i<m;++i){
			int x;
			scanf("%d",&x);
			printf("%d %d\n",ax[x],ay[x]);
		}
	}

}
