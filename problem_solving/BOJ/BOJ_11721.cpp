#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i+=10){
		cout<<s.substr(i,10)<<endl;
	}
}
