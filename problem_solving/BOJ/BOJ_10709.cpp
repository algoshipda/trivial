#include <bits/stdc++.h>
using namespace std;

int h,w;
deque<char> board[105];
int cnt[105][105];
int main()
{
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			char c;
			scanf(" %c ",&c);
			board[i].push_back(c);
		}
	}
	for(int i=0;i<h;++i)for(int j=0;j<w;++j)cnt[i][j]=board[i][j]=='c'?0:-1;
	for(int k=1;k<=w;++k){
		for(int i=0;i<h;++i){
			board[i].push_front('.');
			board[i].pop_back();
		}
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				if(cnt[i][j]==-1 && board[i][j]=='c'){
					cnt[i][j]=k;
				}
			}
		}
	}
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			printf("%d ",cnt[i][j]);
		}
		puts("");
	}
}
