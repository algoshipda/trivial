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
int N;
int num[1003];
int gcd(int a, int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	while(scanf("%d",&N)!=EOF){
		int i,j,k;
		for(i=0;i<N;++i)scanf("%d",&num[i]);
		sort(num,num+N);
		for(i=N-1;i>=0;--i){
			bool valid = true;
			for(j=0;j<N;++j){
				if(i==j)continue;
				if(gcd(num[i],num[j])!=1){
					valid = false;
					break;
				}
			}
			if(valid){
				printf("%d\n",num[i]);
				break;
			}
		}
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
