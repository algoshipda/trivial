#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
vector<int> child[2][1005];
char label[2][1005];
int cnt[2][1005];
char tmp[3005];
int dp[1005][1005];
int n[2];
int make_tree(int t, int cur)
{
	int level=0;
	int c=++n[t];
	label[t][c]=tmp[cur];
	for(int i=cur+1;tmp[i];++i){
		if(tmp[i]=='('){
			++level;
		}else if(tmp[i]==')'){
			--level;
			if(level<0)break;
		}else if(level==1){
			child[t][c].push_back(make_tree(t,i));
		}
	}
	for(int i=0;i<child[t][c].size();++i){
		cnt[t][c]+=1+cnt[t][child[t][c][i]];
	}
	return c;
}

int rec(int u, int v)
{
	int& ret=dp[u][v];
	if(ret!=-1)return ret;
	ret=label[0][u]!=label[1][v];
	if(child[0][u].empty()){
		return ret+=cnt[1][v];
	}
	if(child[1][v].empty()){
		return ret+=cnt[0][u];
	}
	vector<vector<int>> d(child[0][u].size()+2,vector<int>(child[1][v].size()+2,INF));
	d[0][0]=0;
	int asz=child[0][u].size();
	int bsz=child[1][v].size();
	for(int i=0;i<=asz;++i){
		for(int j=0;j<=bsz;++j){
			int nu=i<asz?child[0][u][i]:0;
			int nv=j<bsz?child[1][v][j]:0;
			if(i<asz && j<bsz)d[i+1][j+1]=min(d[i+1][j+1],d[i][j]+rec(nu,nv));
			if(i<asz)d[i+1][j]=min(d[i+1][j],d[i][j]+1+cnt[0][nu]);
			if(j<bsz)d[i][j+1]=min(d[i][j+1],d[i][j]+1+cnt[1][nv]);
		}
	}
	return ret+=d[asz][bsz];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<1005;++i)for(int j=0;j<2;++j)child[j][i].clear();
		memset(cnt,0,sizeof(cnt));
		memset(dp,-1,sizeof(dp));
		memset(n,0,sizeof(n));
		for(int x=0;x<2;++x){
			scanf("%s",tmp);
			make_tree(x,1);
		}
		printf("%d\n",rec(1,1));
	}
}

