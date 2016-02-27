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

string S;
int n;
vector<int> tmp;
vector<int> out;
vector<int>	bckt;
vector<int>	pos2bckt;
vector<int>	bpos;
vector<int>	relabel;
bool cmp(int a, int b) {return S[a] < S[b];}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	S = string("abracadabra");
	int N = (int)S.size();
	tmp = out = bckt = pos2bckt = bpos = relabel = vector<int>(N,0);
	int i,j,k,c,h;
	

	for(i=0;i<N;++i)out[i]=i;
	sort(out.begin(),out.end(),cmp);
	bckt[0] = 0;
	c = 0;
	for(i=0;i<N-1;++i) bckt[i+1] = S[out[i]]==S[out[i+1]]?c:++c;
	for(h=1;h<N;h<<=1){
		for(i=0;i<N;++i)pos2bckt[out[i]] = bckt[i];
		for(i=N-1;i>=0;--i)bpos[bckt[i]] = i;
		for(i=0;i<N;++i)if(out[i] >= N-h)tmp[bpos[bckt[i]]++] = out[i];
		for(i=0;i<N;++i)if(out[i] >= h) tmp[bpos[pos2bckt[out[i]-h]]++] = out[i] - h;

		c=0;
		relabel[0] = 0;
		for(i=0;i<N-1;++i){
			if(bckt[i]!=bckt[i+1])++c;
			else if(tmp[i] >= N-h || tmp[i+1] >= N-h)++c;
			else if(pos2bckt[tmp[i]+h] != pos2bckt[tmp[i+1]+h])++c;
			relabel[i+1]=c;
		}
		swap(out,tmp);
		swap(relabel,bckt);
	}
	for(i=0;i<N;++i)printf("%d %d\n",i,out[i]+1);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

