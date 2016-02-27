#include <bits/stdc++.h>
using namespace std;

int n;
int first;
int tree[400005];
vector<int> c;

void update(int pos, int val)
{
	pos+=first;
	tree[pos]+=val;
	while(pos>>1){
		tree[pos>>1]=tree[pos]+tree[pos^1];
		pos>>=1;
	}
}

int kth(int k)
{
	int idx = 1;
	while(idx<first){
		if(k<=tree[idx<<1]){
			idx<<=1;
		}else{
			k-=tree[idx<<1];
			idx=idx<<1|1;
		}
	}
	return idx-first;
}
int main()
{
	scanf("%d",&n);
	for(first=1;first<n;first<<=1);
	for(int i=0;i<n;++i){
        int x;
		scanf("%d",&x);
		c.push_back(x);
		tree[first+i]=1;
	}
	for(int i=first-1;i>0;--i)tree[i]=tree[i<<1]+tree[i<<1|1];
	sort(c.begin(),c.end());
	
	vector<int> query;
	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		query.push_back(x);
	}
	vector<int> ans;
	for(int i=n-1;i>=0;--i){
		ans.push_back(kth(query[i]+1));
		update(ans.back(),-1);
	}
	for(int i=n-1;i>=0;--i){
		printf("%d\n",c[ans[i]]);
	}
	
}