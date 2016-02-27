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
	string s;
	int N;
	//bucket of i'th suffix
	vector<int> spb;
	//group of i'th in suffix array
	vector<int> bg;
	//bucket's left most 
	vector<int> blm;
	//temp
	vector<int> temp;
	//use for regrouping
	vector<int> reg;
	//result suffix sorting
	vector<int> SA;

	void init(const string& in)
	{
		s = in;
		N = s.size();
		spb = vector<int>(N,0);
		bg = vector<int>(N,0);
		blm = vector<int>(N,0);
		temp = vector<int>(N,0);
		SA = vector<int>(N,0);
		reg = vector<int>(N,0);
	}
	void suffix_array()
	{
		//i'th suffix
		//m i s s i s s i p i
		//0 1 2 3 4 5 6 7 8 9

		//input string
		int i,j,k,c;
		for(i=0;i<N;++i)SA[i]=i;
		
		//sort with first alphabet
		sort(SA.begin(),SA.end(),[](int a, int b){return s[a]<s[b];});
		//for(i=0;i<N;++i)printf("%d %d\n",i,SA[i]);
		
		//grouping
		bg[0] = 0;
		for(i=0,c=0;i<N-1;++i) bg[i+1] = s[SA[i]]==s[SA[i+1]]?c:++c;
		//

		//for(i=0;i<N;++i)printf("%d %d\n",i, bg[i]);

		for(int h=1;h<N;h<<=1){
			//set i'th suffix's bucket
			for(i=0;i<N;++i)spb[SA[i]] = bg[i];
			//calc bucket's left most index
			for(i=N-1;i>=0;--i)blm[bg[i]]=i;
			//------------- pre calc

			//already sorted, just put them bucket's left most position, 
			//and increment the bucket's left most index 
			for(i=0;i<N;++i)if(SA[i] >= N-h) temp[blm[bg[i]]++] = SA[i];
			//SA[i] - h will place buckets' left most index 
			for(i=0;i<N;++i)if(SA[i] >= h) temp[blm[spb[SA[i]-h]]++] = SA[i]-h;


			//regrouping
			c = 0;
			reg[0] = 0;
			for(i=0;i<N-1;++i){
				if(bg[i]!=bg[i+1])++c;
				else if(temp[i] >= N-h || temp[i+1] >= N-h)++c;
				else if(spb[temp[i]+h] != spb[temp[i+1]+h])++c;
				reg[i+1] = c;
			}
			swap(reg,bg);
			swap(SA,temp);
		}
		for(i=0;i<N;++i)printf("%d %d\n",i,SA[i]+1);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	SuffixArray::init("abracadabra");
	SuffixArray::suffix_array();
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
