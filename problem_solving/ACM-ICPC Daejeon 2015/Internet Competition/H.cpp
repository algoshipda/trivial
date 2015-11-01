#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		bool ans = false;
		for(int b=2;b<=64;++b){
			vector<int> v;
			int a=x;
			while(a){
				v.push_back(a%b);
				a/=b;
			}
			vector<int> k=v;
			reverse(k.begin(),k.end());
			if(v==k){
				ans=true;
				break;
			}
		}
		puts(ans?"1":"0");
	}
}