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

int f(int a){return a*a*a;}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    for(int i=2;i<=100;++i){
        for(int j=2;j<i;++j){
            for(int k=j+1;k<i;++k){
                for(int l=k+1;l<i;++l){
                    if(f(i)==f(j)+f(k)+f(l))
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
                }
            }
        }
    }









#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

