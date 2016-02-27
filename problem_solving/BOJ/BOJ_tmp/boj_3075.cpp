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

const int INF = 50000;
const long long LINF = 9876543212345;

int T,N,P,Q;
int meeter[102];
int adj[102][102];


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&P,&Q);
        int i,j,k;
        for(i=1;i<=P;++i)for(j=1;j<=P;++j)adj[i][j]=INF;
        for(i=1;i<=P;++i)adj[i][i]=0;
        for(i=1;i<=N;++i)scanf("%d",&meeter[i]);
        for(i=1;i<=Q;++i){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            adj[a][b] = adj[b][a] = c;
        }
        
        
        for(k=1;k<=P;++k)
            for(i=1;i<=P;++i)
                for(j=1;j<=P;++j)
                    adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
        
        for(i=1;i<=P;++i){
            for(j=1;j<=P;++j){
            //    printf("%d ",adj[i][j]);
            }
          //      puts("");
        }
                
        int x = 0;
        int ans = INF;
        for(i=1;i<=P;++i){
            int sum = 0;
            bool valid = true;
            for(j=1;j<=N;++j){
                int a = adj[meeter[j]][i];
                if(a>=INF){
                    valid = false;
                    break;
                }
                sum += a*a;
            }
            if(ans>sum){
                ans = sum;
                x = i;
            }
        }
        printf("%d %d\n",x,ans);
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

