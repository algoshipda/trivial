#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<char> a(n);
	vector<char> b(n*2);
	for(int i=0;i<n;++i)scanf(" %c ",&a[i]);
	for(int i=0;i<n;++i)scanf(" %c ",&b[i]);
	vector<int> p(n);
	int m=0;
	for(int i=1;i<n;++i){
		while(m>0 && a[m]!=a[i])m=p[m-1];
		if(a[m]==a[i])++m;
		p[i]=m;
	}
	for(int i=0;i<n;++i)b[i+n]=b[i];
	int cnt=0;
	m=0;
	for(int i=0;i<n+n-1;++i){
		while(m>0 && a[m]!=b[i])m=p[m-1];
		if(a[m]==b[i])++m;
		if(m==n){
			++cnt;
			m=p[m-1];
		}
	}
	int g=gcd(cnt,n);
	printf("%d/%d\n",cnt/g,n/g);
}
