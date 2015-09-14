#include <vector>
#include <string>
using namespace std;

vector<string> tokenizer(const string& s, const string& delim=" \n")
{
	vector<string> ret;
	int prv = s.find_first_not_of(delim, 0);
	while(prv != string::npos){
		int nxt = s.find_first_of(delim, prv);
		ret.push_back(s.substr(prv, nxt - prv));
		prv = s.find_first_not_of(delim, nxt);
	}
	return ret;
}
