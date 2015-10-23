#include <bits/stdc++.h>
using namespace std;
int am[1005];
int bm[1005];
vector<int> a[1005];
int v[1005];
int vc;
int dfs(int c)
{
    if(v[c]==vc)return 0;
    v[c]=vc;
    for(int i=0;i<a[c].size();++i){
        int x=a[c][i];
        if(!bm[x]||dfs(bm[x])){
            am[c]=x;
            bm[x]=c;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;++j){
            int y;
            scanf("%d",&y);
            a[i].push_back(y);
        }
    }
    int d=0;
    for(int i=1;i<=n;++i){
        vc++;
        d+=dfs(i);
    }
    printf("%d",d);
}