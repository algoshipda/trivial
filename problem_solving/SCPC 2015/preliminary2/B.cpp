#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int psum[2][1000005];
int l[2],r[2];
int process(int n, int k)
{
	psum[0][1]=0;
	psum[1][1]=0;
	l[0]=a;
	r[0]=a*k;
	l[1]=b;
	r[1]=b*k;
	for(int i=2;i<=n;++i){
		for(int j=0;j<2;++j){
			if(i<=l[j]){
				psum[j][i]=0;
			}else{
				int x=i-l[j];
				int y=max(0,i-r[j]-1);
				psum[j][i]=(psum[j^1][x]-psum[j^1][y]!=x-y)+psum[j][i-1];
			}
		}
	}
	return psum[0][n]!=psum[0][n-1];
}
int main()
{
	setbuf(stdout, NULL);
	int T;
	int test_case;
	scanf("%d", &T);	
	for(test_case = 1; test_case <= T; test_case++) {
		scanf("%d%d%d",&a,&b,&c);
		string ans;
		for(int i=0;i<c;++i){
			int n,k;
			scanf("%d%d",&n,&k);
			ans+=(process(n,k)?'a':'b');
		}
		printf("Case #%d\n%s\n", test_case, ans.c_str());
	}
	return 0;	
}
