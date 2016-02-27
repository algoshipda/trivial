#include <bits/stdc++.h>
using namespace std;

int n;
int num[200005];
bool ok(int a, int b)
{
	while(a%2==0){
		a/=2;
	}
	while(a%3==0){
		a/=3;
	}
	while(b%2==0){
		b/=2;
	}
	while(b%3==0){
		b/=3;
	}
	return a==b;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&num[i]);
	sort(num,num+n);
	bool ans = true;
	for(int i=0;i<n-1;++i){
		if(!ok(num[i],num[i+1])){
			ans = false;
			break;
		}
	}
	puts(ans?"YES":"NO");
}