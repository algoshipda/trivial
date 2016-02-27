#include <vector>
#include <climits>
using namespace std;
typedef long long lld;

vector<vector<lld> > I(int k)
{
	vector<vector<lld> > ret(k, vector<lld>(k));
	for(int i = 0; i < k; ++i) ret[i][i] = 1;
	return ret;
}

vector<vector<lld> > mul(const vector<vector<lld> >& a, const vector<vector<lld> >& b, const lld M = LLONG_MAX)
{
	vector<vector<lld> > ret(a.size(), vector<lld>(b[0].size()));
	for(int i = 0; i < a.size(); ++i){
		for(int j = 0; j < b[0].size(); ++j){
			lld sum = 0;
			for(int k = 0; k < a[0].size(); ++k){
				sum += a[i][k] * b[k][j];
				sum %= M;
			}
			ret[i][j] = sum;
		}
	}
	return ret;
}

vector<vector<lld> > fpow1(const vector<vector<lld> >& a, const lld k, const lld M = LLONG_MAX)
{
	if(!k) return I(a.size());
	if(k&1) return mul(a, fpow1(a, k - 1, M), M);
	vector<vector<lld> > half = fpow1(a, k>>1, M);
	return mul(half, half, M);
}