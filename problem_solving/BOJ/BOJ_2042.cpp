#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n,m,k;

lld psum[1000005];

void update(int pos, int val)
{
	while(pos<=n){
		psum[pos]+=val;
		pos+=(pos&-pos);
	}
}

lld sum(int pos)
{
	lld ret=0;
	while(pos>0){
		ret+=psum[pos];
		pos&=(pos-1);
	}
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		update(i,x);
	}
	for(int i=0;i<m+k;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1){
			int q=sum(y)-sum(y-1);
			update(y,z-q);
		}else{
			printf("%lld\n",sum(z)-sum(y-1));
		}
	}
}
