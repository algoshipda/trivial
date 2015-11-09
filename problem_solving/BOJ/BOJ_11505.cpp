#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int MOD=1e9+7;
int n,m,k;
int a[1000005];
int b[4000005];

void build(int id=1, int l=0, int r=n-1)
{
    if(l==r){
        b[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    b[id]=(lld)b[id<<1]*b[id<<1|1]%MOD;
}

void update(int pos, int val, int id=1, int l=0, int r=n-1)
{
    if(l==r){
        b[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(pos,val,id<<1,l,mid);
    }else{
        update(pos,val,id<<1|1,mid+1,r);
    }
    b[id]=(lld)b[id<<1]*b[id<<1|1]%MOD;
}

int query(int x, int y, int id=1, int l=0, int r=n-1)
{
    if(y<l || r<x)return 1;
    if(x<=l && r<=y)return b[id];
    int mid=(l+r)>>1;
    return (lld)query(x,y,id<<1,l,mid)*query(x,y,id<<1|1,mid+1,r)%MOD;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);     
    }
    build();
    for(int i=0;i<m+k;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1){
            update(y-1,z);
        }else{
            printf("%d\n",query(y-1,z-1));
        }
    }
}
