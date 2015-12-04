#include <bits/stdc++.h>
using namespace std;

int n,m;

int psum[1025][1025];
void update(int x, int y, int val)
{
	for(int i=x;i<=n;i+=(i&-i)){
		for(int j=y;j<=n;j+=(j&-j)){
			psum[i][j]+=val;
		}
	}
}

int sum(int x, int y)
{
	int ret=0;
	for(int i=x;i;i&=(i-1)){
		for(int j=y;j;j&=(j-1)){
			ret+=psum[i][j];
		}
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int x;
			scanf("%d",&x);
			update(i,j,x);
		}
	}
	for(int i=0;i<m;++i){
		int k;
		scanf("%d",&k);
		if(k){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(x1>x2 || x1==x2 && y1>y2){
				swap(x1,x2);
				swap(y1,y2);
			}
			printf("%d\n",sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1));
		}else{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			int q=sum(x,y)-sum(x-1,y)-sum(x,y-1)+sum(x-1,y-1);
			update(x,y,z-q);
		}
	}
}
