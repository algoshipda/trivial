#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+100;
struct Line{
	int a, b;
	Line(int _a=0, int _b=0):a(_a),b(_b){}
	bool operator < (const Line& B) const
	{
		if(a!=B.a)return a<B.a;
		return b>B.b;
	};
};


vector<Line> v;
int n;
int lis()
{
	vector<int> lis(n+1,INF);
	for(int i=0;i<v.size();++i){
		int idx=upper_bound(lis.begin(),lis.end(),-v[i].b)-lis.begin();
		lis[idx]=-v[i].b;
	}
	return lower_bound(lis.begin(),lis.end(),INF)-lis.begin();
}
int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	int T;
	int test_case;
	scanf("%d", &T);	
	for(test_case = 1; test_case <= T; test_case++) {
		scanf("%d",&n);
		v=vector<Line>(n);
		for(int i=0;i<n;++i)scanf("%d%d",&v[i].a,&v[i].b);
		sort(v.begin(),v.end());
		int ans=lis();
		printf("Case #%d\n%d\n", test_case, ans);
	}
	return 0;
}
