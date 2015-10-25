#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int ok(int x, int k, int t)
{
    long long q=0;
    long long w=1;
    for(int i=0;i<x;++i){
        q+=w;
        w*=k;
        if(q>=t)return 1;
    }
    return 0;
}
int eq(int x, int k, int t)
{
    long long q=0;
    long long w=1;
    for(int i=0;i<x;++i){
        q+=w;
        w*=k;
        if(q>t)return 0;
    }
    return q==t;
}
int chk(int x, int lb, int rb, int len)
{
    int ret=-1;
    for(int i=2;i<=len;++i){
        int l=lb;
        int r=rb;
        while(l<r){
            int mid=(l+r)>>1;
            if(ok(i,mid,x)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        if(!eq(i,l,x))continue;
        if(ret==-1 || ret>l)ret=l;
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        scanf("%d",&n);
        vector<int> d;
        for(int i=1;(lld)i*i<=n;++i){
            if(n%i==0){
                d.push_back(i);
                if(n/i!=i)d.push_back(n/i);
            }
        }
        sort(d.begin(),d.end());
        int x=n;
        int k=0;
        while(x){
            x>>=1;
            k++;
        }
        int ans=max(n-1,2);
        for(int i=0;i<d.size();++i){
            int q=chk(d[i],n/d[i]+1,max(n-1,2),k);
            if(q!=-1)ans=min(ans,q);
        }
        printf("Case #%d\n%d\n",tc,ans);
    }   
}