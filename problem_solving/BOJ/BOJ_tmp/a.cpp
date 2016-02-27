#include <bits/stdc++.h>
using namespace std;

int n;
int num[103];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&num[i]);
	priority_queue<int> q;
	for(int i=1;i<n;++i)q.push(num[i]);
	int ans = 0;
	while(q.top()>=num[0]){
		int cur = q.top();
		q.pop();
		q.push(cur-1);
		++num[0];
		++ans;
	}
	printf("%d\n",ans);
}