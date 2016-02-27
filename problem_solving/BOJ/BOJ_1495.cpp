<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int n,s,m;
int a[105];
int main()
{
	scanf("%d%d%d",&n,&s,&m);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	vector<int> dp1(m+1);
	dp1[s] = 1;
	for(int i=0;i<n;++i){
		vector<int> dp2(m+1);
		for(int j=0;j<=m;++j){
			if(dp1[j]){
				if(j-a[i]>=0)dp2[j-a[i]]=1;
				if(j+a[i]<=m)dp2[j+a[i]]=1;
			}
		}
		swap(dp1,dp2);
	}
	int ans=-1;
	for(int i=0;i<=m;++i)if(dp1[i])ans=i;
	printf("%d\n",ans);
}
=======
#include <iostream>
#include <algorithm>
using namespace std;

const int MN = 105;
const int MM = 1005;

int n, s, m, v[MN];

int main()
{
	cin >> n >> s >> m;
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}

	vector<int> dp1(m + 1, 0);
	vector<int> dp2(m + 1, 0);

	dp1[s] = 1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= m; ++j){
			if(j + v[i] <= m){
				dp2[j + v[i]] |= dp1[j];
			}
			if(j - v[i] >= 0){
				dp2[j - v[i]] |= dp1[j];
			}
		}
		swap(dp1, dp2);
		fill(dp2.begin(), dp2.begin() + m + 1, 0);
	}

	for(int i = m; i >= 0; --i){
		if(dp1[i]){
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}
>>>>>>> 5b18d34fd3c47d6b2c01f29aa6d9f163f2723a0d
