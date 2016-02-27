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

int entered[1000005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int ans = 0;
	int enter = 0;
	for(int i=0;i<N;++i){
        char c; int k;
        scanf(" %c %d",&c,&k);
        if(c=='+'){
            entered[k] = 1;
            enter++;
        }else{
            if(!entered[k]){
                ans++;
            }else{
                entered[k] = 0;
                --enter;
            }
        }
        ans = max(ans, enter);
	}
    printf("%d\n",ans);

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

