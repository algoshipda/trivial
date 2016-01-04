#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> tokenizer(const string& s, const string& delim=" \n")
{
	vector<int> ret;
	size_t prv = s.find_first_not_of(delim, 0);
	while(prv != string::npos){
		size_t nxt = s.find_first_of(delim, prv);
		ret.push_back(atoi(s.substr(prv, nxt - prv).c_str()));
		prv = s.find_first_not_of(delim, nxt);
	}
	return ret;
}

vector<int> go(vector<int> v)
{
	vector<int> ret(v.size()-1);
	for(int i=1;i<v.size();++i){
		ret[i-1]=v[i]-v[i-1];
	}
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	vector<int> v=tokenizer(s, ", \n");
	for(int i=0;i<m;++i)v=go(v);
	for(int i=0;i<v.size();++i){
		printf("%d",v[i]);
		if(i!=(int)v.size()-1)printf(",");
	}
	puts("");
}
