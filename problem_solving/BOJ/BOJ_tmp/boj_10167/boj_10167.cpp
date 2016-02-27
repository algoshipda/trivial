#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#define point(A,B) make_pair((A),(B))
#define sz(A) (int)(A.size())
#define pb(A) push_back((A))
using namespace std;
int n;
map< pair<int,int>, int > s;
vector<int> X;
vector<int> Y;
vector< pair<int, int> > V;
vector< vector< pair<int, int> > > P;
struct BIT{
        long long ls[12005];
        long long ms[12005];
        long long rs[12005];
        long long s[12005];
        int last;
        int x;
        BIT(){}
        BIT(int k){
                for(last=1;last<k;last<<=1);
                x = last+k;
                init();
        }
        void init(){
                memset(ls,0,sizeof(long long)*x);
                memset(ms,0,sizeof(long long)*x);
                memset(rs,0,sizeof(long long)*x);
                memset(s,0,sizeof(long long)*x);
        }
};
int main()
{
        scanf("%d",&n);
        for(int i=0;i<n;++i){
                int x,y,w;
                scanf("%d%d%d",&x,&y,&w);
                X.pb(x);
                Y.pb(y);
                V.pb(point(y,x));
                s[point(x,y)]=w;
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());
        P = vector< vector< pair<int,int> > >(sz(Y));
        for(int i=0;i<sz(V);++i){
                int idx = lower_bound(Y.begin(),Y.end(),V[i].first)-Y.begin();
                P[idx].pb(point(V[i].second, s[point(V[i].second,V[i].first)]));
        }
        BIT bit(sz(X));

        long long ans = 0;
        for(int i=0;i<sz(P);++i){
                bit.init();
                for(int j=i;j<sz(P);++j){
                        for(int k=0;k<sz(P[j]);++k){
                                int w = P[j][k].second;
                                int idx = lower_bound(X.begin(),X.end(), P[j][k].first)-X.begin()+bit.last;
                                bit.ls[idx]+=w;
                                bit.rs[idx]+=w;
                                bit.s[idx]+=w;
                                bit.ms[idx]+=w;
                                for(idx>>=1; idx>0;idx>>=1){
                                        int l = idx*2;
                                        int r = idx*2+1;
                                        bit.ls[idx] = max(bit.ls[l], bit.s[l]+bit.ls[r]);
                                        bit.rs[idx] = max(bit.rs[r], bit.s[r]+bit.rs[l]);
                                        bit.s[idx] = bit.s[l] + bit.s[r];
                                        bit.ms[idx] = max(bit.ms[l],max(bit.ms[r],bit.rs[l]+bit.ls[r]));
                                }
                        }
                        ans = max(ans,bit.ms[1]);
                }
        }
        printf("%lld\n",ans);
}
