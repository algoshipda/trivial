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

int N,M;
int matched[53][53];
int visited[53];
int source[52];
int sink[52];
int vcnt;


int dfs(int a)
{
    visited[a] = vcnt;
    for(int i=1;i<=M;++i){
        if(matched[a][i])continue;
        
        // bMatch[i] == -1
        if(sink[i]){
            --sink[i];
            matched[a][i] = 1;
            return 1;
        }
        
        // dfs(bMatch[i]);
        for(int j=1;j<=N;++j){
            if(!matched[j][i])continue;
            if(visited[j] == vcnt)continue;
            if(dfs(j)){
                matched[j][i] = 0;
                matched[a][i] = 1;
                return 1;
            }
        }
    }
    return 0;
}
void matching()
{
    for(int i=1;i<=N;++i){
        for(int j=0;j<source[i];++j){
            ++vcnt;
            if(!dfs(i)){
                printf("-1");
                exit(0);
            }
        }
    }
}

int cycle(int v, int des, pii lower)
{
    visited[v] = vcnt;
    for(int i=1;i<=M;++i){
        if(mp(v,i)<=lower)continue;
        if(matched[v][i])continue;
        
        //사이클이 만들어짐
        if(i==des){
            matched[v][des] = 1;
            return 1;
        }
        
        //뒤에 애들을 밀어서 사이클을 만들 수 있는지 본다.
        for(int j=1;j<=N;++j){  
            if(!matched[j][i])continue;
            if(mp(j,i)<=lower)continue;
            if(visited[j] == vcnt)continue;
            if(cycle(j,des,lower)){
                //사이클이 만들어지더라
                matched[j][i] = 0;
                matched[v][i] = 1;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
	freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&M);
    int a=0;
    int b=0;
    for(int i=1;i<=N;++i){
        scanf("%d",&source[i]);
        a+=source[i];
    }
    for(int i=1;i<=M;++i){
        scanf("%d",&sink[i]);
        b+=sink[i];
    }
    if(a!=b){
        puts("-1");
        return 0;
    }
    matching();
    if(accumulate(sink,sink+M,0)!=0){
        printf("-1");return 0;
    }
    
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(!matched[i][j])continue;
            ++vcnt;
            if(cycle(i,j,mp(i,j)))
                matched[i][j] = 0;
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            printf("%c",matched[i][j]?'1':'0');
        }
        puts("");
    }
	fclose(stdin);
}

