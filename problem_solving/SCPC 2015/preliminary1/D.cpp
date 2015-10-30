#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;++tc){
        int n;
        scanf("%d",&n);
        vector<pair<pair<int,int>,pair<int,int> > > p(n);
        vector<int> h(n+n);
        vector<int> v(n+n);
        for(int i=0;i<n;++i){
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1<<=1;
            y1<<=1;
            x2<<=1;
            y2<<=1;
            h[i]=x1;
            h[i+n]=x2;
            v[i]=y1;
            v[i+n]=y2;
            p[i]=make_pair(make_pair(x1,y1),make_pair(x2,y2));
        }
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        h.erase(unique(h.begin(),h.end()),h.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int ans1=2e9+100;
        int ans2=2e9+100;
        for(int i=0;i<h.size();++i){
            for(int j=i;j<h.size();++j){
                int m=((long long)h[i]+h[j])>>1;
                int tmp=0;
                for(int k=0;k<n;++k){
                    tmp=max(tmp,min(abs(p[k].first.first-m),abs(p[k].second.first-m)));
                }
                ans1=min(ans1,tmp);
            }
        }
        for(int i=0;i<v.size();++i){
            for(int j=i;j<v.size();++j){
                int m=((long long)v[i]+v[j])>>1;
                int tmp=0;
                for(int k=0;k<n;++k){
                    tmp=max(tmp,min(abs(p[k].first.second-m),abs(p[k].second.second-m)));
                }
                ans2=min(ans2,tmp);
            }
        }
        int ans=max(ans1,ans2);
        printf("Case #%d\n%d",tc,ans>>1);
        if(ans&1)printf(".5");
        puts("");
    }
}