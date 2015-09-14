#include <vector>
#include <string>
using namespace std;

vector<string> tokenizer(const string& s, const string& delim=" \n")
{
	vector<string> ret;
	size_t prv = s.find_first_not_of(delim, 0);
	while(prv != string::npos){
		size_t nxt = s.find_first_of(delim, prv);
		ret.push_back(s.substr(prv, nxt - prv));
		prv = s.find_first_not_of(delim, nxt);
	}
	return ret;
}

int main(){}