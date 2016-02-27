#include <bits/stdc++.h>
using namespace std;

int n,k;
int psum[300005];

int main()
{
    scanf("%d%d",&n,&k);
    unordered_map<int,int> m;
    vector<int> coord(n+2*k);
    vector<int> p(n);
    vector<pair<int,int>> q(k);
    for(int i=0;i<n;++i){
        scanf("%d",&p[i]);
        coord[i]=p[i];
    }
    for(int i=0;i<k;++i){
        scanf("%d%d",&q[i].first,&q[i].second);
        coord[n+i]=q[i].first;
        coord[n+i+k]=q[i].second;
    }
    sort(coord.begin(),coord.end());
    coord.erase(unique(coord.begin(),coord.end()),coord.end());
    n=coord.size();
    for(int i=0;i<coord.size();++i){
        m[coord[i]]=i+1;
    }
    for(int i=0;i<p.size();++i)psum[m[p[i]]]++;
	for(int i=1;i<=coord.size();++i)psum[i]+=psum[i-1];
    for(int i=0;i<k;++i){
        int x=m[q[i].first];
        int y=m[q[i].second];
        printf("%d\n",psum[y]-psum[x-1]);
    }
}
