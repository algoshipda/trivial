#include <bits/stdc++.h>
using namespace std;

bool chk[105];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;++j){
			int k;
			scanf("%d",&k);
			chk[k]=1;
		}
	}
	bool valid=true;
	for(int i=1;i<=m;++i){
		if(!chk[i]){
			valid=false;
			break;
		}
	}
	puts(valid?"YES":"NO");
}
