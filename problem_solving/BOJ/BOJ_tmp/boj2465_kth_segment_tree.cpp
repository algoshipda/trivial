#include <bits/stdc++.h>
using namespace std;

int n;
int s[400005];
vector<int> c;
void build(int id=1, int l=0, int r=n-1)
{
	if(l==r){
		s[id]=1;
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	s[id]=s[id<<1]+s[id<<1|1];
}

void update(int pos, int val, int id=1, int l=0, int r=n-1)
{
	if(l==r){
		s[id]+=val;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(pos, val, id<<1,l,mid);
	else update(pos, val, id<<1|1,mid+1,r);
	s[id]=s[id<<1]+s[id<<1|1];
}

int kth(int k, int id=1, int l=0, int r=n-1)
{
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	if(k<=s[id<<1]){
		return kth(k,id<<1,l,mid);
	}else{
		return kth(k-s[id<<1],id<<1|1,mid+1,r);
	}
}

int main()
{
	scanf("%d",&n);
	build();
	for(int i=0;i<n;++i){
        int x;
		scanf("%d",&x);
		c.push_back(x);
	}
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