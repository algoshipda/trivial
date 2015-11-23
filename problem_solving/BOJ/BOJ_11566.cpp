#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005], b[1005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=0;i<m;++i)scanf("%d",&b[i]);
	int x=-1;
	int y=-1;
	for(int k=1;k<m;++k){
		for(int i=0;i<m;++i){
			if(i+(n-1)*k>=m)break;
			int j;
			for(j=0;j<n;++j){
				if(b[i+j*k]!=a[j])break;
			}
			if(j==n){
				if(x==-1){
					x=k;
				}
				y=k;
				break;
			}		
		}
	}
	if(x==-1){
		puts("-1");
		return 0;
	}
	printf("%d %d\n",x-1,y-1);
}
