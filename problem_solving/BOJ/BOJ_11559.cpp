#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<vector<char>> board(6,vector<char>(13,'.'));
int vis[6][12];
int vcnt=1;

vector<pair<int,int>> founded;
vector<pair<int,int>> tmp;
void dfs(int cx, int cy)
{
	vis[cx][cy]=vcnt;
	tmp.push_back(make_pair(cx,cy));
	for(int i=0;i<4;++i){
		int nx=cx+dx[i];
		int ny=cy+dy[i];
		if(0<=nx && nx<6 && 0<=ny && ny<12 && vis[nx][ny]!=vcnt && board[nx][ny]==board[cx][cy])dfs(nx,ny);
	}
}
int main()
{
	for(int i=0;i<12;++i){
		for(int j=0;j<6;++j){
			char c;
			cin>>c;
			board[j][11-i]=c;
		}
	}
	int cnt=0;
	while(true){
		for(int i=0;i<6;++i){
			for(int j=0;j<12;++j){
				tmp.clear();
				if(board[i][j]!='.' && vis[i][j]!=vcnt){
					++vcnt;
					dfs(i,j);
				}
				if(tmp.size()>=4){
					for(int k=0;k<tmp.size();++k){
						founded.push_back(tmp[k]);
					}
				}
			}
		}
		if(founded.empty()){
			printf("%d\n",cnt);
			return 0;
		}
		sort(founded.begin(),founded.end());
		founded.erase(unique(founded.begin(),founded.end()),founded.end());
		reverse(founded.begin(),founded.end());
		++cnt;
		for(int k=0;k<founded.size();++k){
			int x=founded[k].first;
			int y=founded[k].second;
			board[x].erase(board[x].begin()+y);
		}
		for(int k=0;k<6;++k)board[k].resize(13,'.');
		founded.clear();
	}
}

