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

const lld D = 1234567891;

lld W[26];
char a[1505];
char b[1505];
int A[1505];
int B[1505];

int cnta[1505][26];
int cntb[1505][26];
unordered_map<lld, int> hashset;
int N,M;

bool equal(int x, int y, int c)
{
	int i,j,k,q;
	vector<int> cntA(26,0);
	vector<int> cntB(26,0);
	i=x;
	j=y;
	
	if(i+c>N || j+c>M)return false;
	
	for(int q=0;q<26;++q){
		cntA[q] -= cnta[i][q];
		cntB[q] -= cntb[j][q];
	}
	i=x+c;
	j=y+c;
	for(int q=0;q<26;++q){
		cntA[q] += cnta[i][q];
		cntB[q] += cntb[j][q];
	}
	return cntA==cntB;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%s %s",a,b);
	int i,j,k;
	W[0] = 1;
	for(i=1;i<26;++i){
		W[i] = W[i-1] * D;
	}
	N = strlen(a);
	M = strlen(b);
	for(i=0;i<N;++i)A[i] = a[i]-'a';
	for(i=0;i<M;++i)B[i] = b[i]-'a';
	cnta[1][A[0]]++;
	cntb[1][B[0]]++;
	for(i=1;i<N;++i){
		for(j=0;j<26;++j)cnta[i+1][j]=cnta[i][j];
		cnta[i+1][A[i]]++;
	}
	for(i=1;i<M;++i){
		for(j=0;j<26;++j)cntb[i+1][j]=cntb[i][j];
		cntb[i+1][B[i]]++;
	}
	for(i=0;i<N;++i){
		lld hashed = 0;
		for(j=i;j<N;++j){
			int x = j-i;
			hashed += W[A[j]];
			hashset[hashed] = i;
		}
	}

	int ans = 0;
	for(i=0;i<M;++i){
		lld hashed = 0;
		for(j=i;j<M;++j)
			hashed += W[B[j]];
		
		for(j=M-1;j>=i;--j){
			int x = j-i;
			if(hashset.count(hashed)){
				if(equal(hashset[hashed], i, x+1)){
					ans = max(ans,x+1);	

				} 	
			} 
			hashed -= W[B[j]];
		}
	}
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
