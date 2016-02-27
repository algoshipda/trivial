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
	string S;
	int N;
	vector<int> BH;
	vector<int> B2H;
	vector<int> PTB;
	vector<int> BL;
	vector<int> B;
	vector<int> TMP;

	void init(const string& X)
	{
		S = X;
		N = (int)S.size();
		BH = vector<int>(N,0);
		B2H = vector<int>(N,0);
		PTB = vector<int>(N,0);
		BL = vector<int>(N,0);
		B = vector<int>(N,0);
		TMP = vector<int>(N,0);
	}

	void process()
	{
		int i,j,k;
		for(i=0;i<N;++i)BH[i] = i;
		sort(BH.begin(),BH.end(),[](int a, int b){ return S[a] < S[b];});
		B[0] = 0;
		int c = 0;
		for(i=0;i<N-1;++i)B[i+1] = S[BH[i]]==S[BH[i+1]]?c:++c;
		for(int h=1;h<N;h<<=1){
			for(i=0;i<N;++i)PTB[BH[i]] = B[i];
			for(i=N-1;i>=0;--i)BL[B[i]] = i;
			for(i=0;i<N;++i)if(BH[i]>=N-h)B2H[BL[B[i]]++] = BH[i]; 
			for(i=0;i<N;++i)if(BH[i]>=h)B2H[BL[PTB[BH[i]-h]]++] = BH[i]-h;
			c=0;
			TMP[0] = 0;
			for(i=0;i<N-1;++i){
				if(B[i]!=B[i+1])++c;
				else if(B2H[i]>=N-h || B2H[i+1]>=N-h)++c;
				else if(PTB[B2H[i]+h] != PTB[B2H[i+1]+h])++c;
				TMP[i+1] = c;
			}
			swap(BH,B2H);
			swap(TMP,B);
		}
		for(i=0;i<N;++i)printf("%d %d\n",i,BH[i]+1);
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif

	SuffixArray::init("abracadabra");
	SuffixArray::process();
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}



