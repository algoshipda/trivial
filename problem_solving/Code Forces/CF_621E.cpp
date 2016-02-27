#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MOD = 1e9+7;
int N,B,K,X;
int cnt[15];

vector<vector<int> > q;
vector<vector<int> > mult(const vector<vector<int> > a, const vector<vector<int> > b)
{
	vector<vector<int> > ret(a.size(), vector<int>(b[0].size(),0));
	for(int i=0;i<ret.size();++i){
		for(int j=0;j<ret[0].size();++j){
			for(int k=0;k<a[0].size();++k){
				ret[i][j]=((lld)a[i][k]*b[k][j]+ret[i][j])%MOD;
			}
		}
	}
	return ret;
}

vector<vector<int> > fpow(vector<vector<int> > &mat, int k)
{
	if(k==0){
		return q;
	}
	if(k%2){
		return mult(mat,fpow(mat,k-1));
	}
	vector<vector<int> > half=fpow(mat,k/2);
	return mult(half,half);
}

int main()
{
	cin>>N>>B>>K>>X;
	for(int i=0;i<N;++i){
		int x;
		cin>>x;
		cnt[x]++;
	}
	vector<vector<int> > a(X,vector<int>(X));
	for(int i=0;i<X;++i){
		for(int j=1;j<=9;++j){
			int k=(i*10+j)%X;
			a[k][i]+=cnt[j];
		}
	}
	q=vector<vector<int> >(X,vector<int>(X,0));
	for(int i=0;i<q.size();++i)q[i][i]=1;
	vector<vector<int> > ans=fpow(a,B);
	cout<<ans[K][0]<<endl;
}