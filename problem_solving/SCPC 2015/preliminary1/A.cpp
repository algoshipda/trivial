#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        long long k;
        scanf("%d",&n);
        n++;
        vector<long long> pos(n);
        for(int i=1;i<n;++i)scanf("%lld",&pos[i]);
        scanf("%lld",&k);
        int ans=0;
        bool valid=true;
        int nxt;
        for(int cur=0;cur!=n-1 && valid;cur=nxt){
            for(int j=cur+1;j<n;++j){
                if(pos[cur]+k>=pos[j]){
                    nxt=j;
                }else{
                    if(j==cur+1)valid=false;
                    break;
                }
            }
            ++ans;
        }
        printf("Case #%d\n%d\n",tc,valid?ans:-1);
    }
}