#include <bits/stdc++.h>
#include <cassert>
#define pb(a) push_back((a))
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


namespace SuffixArray
{
	typedef char val_t;
	const int MAX_N = 4096;

	int n;
	val_t in[MAX_N];
	int out[MAX_N], temp[MAX_N];
	int pos2bckt[MAX_N];

	int bckt[MAX_N], relabel[MAX_N];
	int bpos[MAX_N];

	void build() {
		for (int i = 0; i < n; i++) out[i] = i;
		sort(out, out + n, [](int a,int bckt) { return in[a] < in[bckt];});
		for(int i = 0, c = 0; i < n; i++) { bckt[i] = c; if (i+1 == n || in[out[i]] != in[out[i+1]]) c++; }
		for(int h = 1; h < n; h <<= 1) {
			for (int i = 0; i < n; i++) pos2bckt[out[i]] = bckt[i];
			for (int i = n-1; i>=0; i--) bpos[bckt[i]] = i;
			for(int i=0;i<n;++i)printf("%d %d\n",i,bckt[i]);
			memset(temp,0,sizeof(temp));
			for (int i = 0; i < n; i++) if (out[i] >= n-h) temp[bpos[bckt[i]]++] = out[i];
			for(int i=0;i<n;++i)printf("%d %d\n",i,bpos[out[i]]);
			for (int i = 0; i < n; i++) if (out[i] >= h) temp[bpos[pos2bckt[out[i]-h]]++] = out[i]-h;

			relabel[0] = 0;
			for (int i = 1, c = 0; i < n-1; i++) {
				if (bckt[i] != bckt[i+1]) c++;
				else if(temp[i+1] >= n-h || temp[i] >= n-h) {c++;}
				else if(pos2bckt[temp[i+1] + h] != pos2bckt[temp[i]+h]) c++;
				relabel[i+1] = c;
			}
			memcpy(out, temp, sizeof(temp[0]) * n);
			memcpy(bckt, relabel, sizeof(relabel[0]) * n);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	const char *str = "abracadabra";
	SuffixArray::n = strlen(str);
	strcpy(SuffixArray::in, str);
	SuffixArray::build();
	printf("11,8,1,4,6,9,2,5,7,10,3,\n");
	for(int i = 0; i < SuffixArray::n; i++) {
		printf("%d,", SuffixArray::out[i]+1);
	}
	printf("\n");

	return 0;
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

