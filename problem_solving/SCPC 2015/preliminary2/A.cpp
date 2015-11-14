#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lld;

lld a[100005];
int n;
lld gcd(lld a, lld b)
{
	return b?gcd(b,a%b):a;
}
int main(void) {
	setbuf(stdout, NULL);
	int T;
	int test_case;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%lld",&a[i]);
		vector<lld> d;
		for(int i=1;i<n;++i)d.push_back(a[i]-a[i-1]);
		sort(d.begin(),d.end());
		d.erase(unique(d.begin(),d.end()),d.end());
		if(d.size()==1 && d[0]==0){
			printf("Case #%d\n1\n", test_case);
			continue;
		}else if(d.size()>1 && d[0]==0){
			printf("Case #%d\n0\n", test_case);
			continue;
		}
		lld g=d[0];
		for(int i=1;i<d.size();++i)g=gcd(g,d[i]);
		int ans=0;
		for(lld i=1;i*i<=g;++i){
			if(g%i==0){
				++ans;
				if(i!=g/i){
					++ans;
				}
			}
		}
		printf("Case #%d\n%d\n", test_case, ans);
	}
	return 0;
}
