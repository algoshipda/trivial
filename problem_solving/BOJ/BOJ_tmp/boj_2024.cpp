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

int M;
pii p[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    while(scanf("%d",&M)!=EOF){
        int i;
        for(i=0;scanf("%d%d",&p[i].ff,&p[i].ss),p[i].ff!=0 || p[i].ss!=0;++i);
        int N = i;
        sort(p,p+N);
        
        int cnt = 0;
        i = 0;
        int cur = 0;
        bool valid = true;
        while(cur < M){
            int max_line = 0;
            while(i < N && p[i].ff <= cur){
                max_line = max(max_line, p[i].ss);
                ++i;
            }
            if(max_line <= cur) {
                valid = false;
                break;
            }
            cur = max_line;
            ++cnt;
        }
        if(valid)printf("%d\n",cnt);
        else puts("0");
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

