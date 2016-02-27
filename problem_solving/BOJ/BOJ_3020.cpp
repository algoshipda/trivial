#include <bits/stdc++.h>
using namespace std;

int n,h;
int psum[2][500005];
int main()
{
	scanf("%d%d",&n,&h);
	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		if(i%2){
			psum[1][h-x+1]++;
		}else{
			psum[0][x]++;
		}
	}
	for(int i=1;i<=h;++i){
		psum[1][i]+=psum[1][i-1];
	}
	for(int i=h;i>=1;--i){
		psum[0][i]+=psum[0][i+1];
	}
	int m=(int)1e9;
	int cnt=0;
	for(int i=1;i<=h;++i){
		int x=psum[0][i]+psum[1][i];
		if(x<m){
			m=x;
			cnt=1;
		}else if(x==m){
			++cnt;
		}
	}
	printf("%d %d\n",m,cnt);
}
