#include <bits/stdc++.h>
using namespace std;

int n,c;
int a[1005];
map<int,int> cnt;
map<int,int> first;
bool cmp(int a, int b)
{
	if(cnt[a]!=cnt[b])return cnt[a]>cnt[b];
	return first[a]<first[b];
}
int main()
{
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		if(!first.count(a[i])){
			first[a[i]]=i;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;++i)printf("%d ",a[i]);
}
