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
int cnt[100005];
int perm[100005];
int used[100005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&perm[i]);
        cnt[perm[i]]++;
    }
    int cur = 1;
    for(int i=0;i<N;++i){
        if(cnt[perm[i]]>1 || perm[i]>N){
            while(cnt[cur])++cur;
            printf("%d ",cur);
            cnt[perm[i]]--;
            cnt[cur]++;
        }else printf("%d ",perm[i]);
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

