#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

namespace SuffixArray{
	string S("banana");
	int n = S.size();
	vector<int> bckt;
	vector<int> bpos;
	vector<int> pos2bckt;
	vector<int> out;
	vector<int> tmp;
	vector<int> relabel;

	void init()
	{
		bckt = bpos = pos2bckt = out = tmp = relabel = vector<int>(n,0);
	}

	void suffix_array(){
		int i,j,k,h,c;
		for(i=0;i<n;++i)out[i]=i;
		sort(out.begin(),out.end(),[](int a, int b){return S[a]<S[b];});
		c=0;
		bckt[0]=0;
		for(i=0;i<n-1;++i) bckt[i+1] = S[out[i]]==S[out[i+1]]?c:++c;
		for(h=1;h<n;h<<=1){
			for(i=0;i<n;++i)pos2bckt[out[i]]=bckt[i];
			for(i=n-1;i>=0;--i)bpos[bckt[i]]=i;
			for(i=0;i<n;++i)if(n-out[i]-1<h)tmp[bpos[pos2bckt[out[i]]]++] = out[i];
			for(i=0;i<n;++i)if(out[i] - h >= 0)tmp[bpos[pos2bckt[out[i]-h]]++] = out[i] - h;
			c=0;
			relabel[0] = 0;
			for(i=0;i<n;++i)printf("%d %d\n",i,bckt[i]);
			for(i=0;i<n-1;++i){
				if(bckt[i]!=bckt[i+1])++c;
				else if(tmp[i]>=n-h ||tmp[i+1]>=n-h)++c;
				else if(pos2bckt[tmp[i+1]+h] != pos2bckt[tmp[i]+h])++c;
				relabel[i+1]=c;
			}
			swap(relabel,bckt);
			swap(tmp,out);
		}
		for(i=0;i<n;++i)printf("%d %d\n",i,out[i]+1);

	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif

 	SuffixArray::init();
 	SuffixArray::suffix_array();
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}