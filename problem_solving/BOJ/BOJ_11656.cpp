#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	vector<string> v;
	for(int i=0;i<s.size();++i){
		v.push_back(s.substr(i));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<s.size();++i)cout<<v[i]<<endl;
}
