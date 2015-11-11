#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> v(n);
		for(int i=0;i<n;++i)scanf("%d",&v[i]);
		sort(v.begin(),v.end());
		deque<int> q;
		for(int i=n-1;i>=0;--i){
			if(i&1)q.push_back(v[i]);
			else q.push_front(v[i]);
		}
		int ans=0;
		for(int i=0;i<n;++i)ans=max(ans,abs(q[i]-q[(i+1)%n]));
		printf("%d\n",ans);
	}
}
