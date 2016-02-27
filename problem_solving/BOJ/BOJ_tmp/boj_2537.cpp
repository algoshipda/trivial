#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())

using namespace std;
const int INF = 987654321;
const long long LINF = 9876543212345;
const double DINF = 987654321.0;

int N,L,K;

int l[1005];
int d[1005];
int v[1005];
double cache[1005];

int cnt;
double get(double time, int a, int b)
{
        if(a<0 || b<0) return DINF;
        double adis = v[a] * time;
        double bdis = v[b] * time;
        int al = L - l[a] + 1;
        int bl = L - l[b] + 1;
        int an = (int)(adis/al);
        int bn = (int)(bdis/bl);
        int adir = d[a] ^ (an%2);
        int bdir = d[b] ^ (bn%2);
        double apos = adis - an * al;
        double bpos = bdis - bn * bl;
        
        apos = adir?al-(apos+1):apos;
        bpos = bdir?bl-(bpos+1):bpos;
        //printf("%f %d %d %f %f %d %d %d %d\n",time,a,b,bpos,apos,l[a],v[a]+v[b],adir,bdir);
        if(apos < bpos){
                if(apos + l[a] >= bpos)return 0.0;
        }else{
                if(bpos + l[b] >= apos)return 0.0;
        }
        
        if(adir!=bdir){
                if(!adir){
                        if(apos<bpos){
                                //가까워짐
                                return (bpos - (apos+l[a]))/(v[a]+v[b]); 
                        }else{
                                //멀어짐
                                double first = min((al-apos)/v[a],bpos/v[b]);
                                return first + get(time + first, a,b);
                        }
                }else{
                        if(apos<bpos){
                                //멀어짐
                                double first = min((bl-bpos)/v[b],apos/v[a]);
                                return first + get(time + first, a,b);
                        }else{
                                //가까워짐
                                return (apos - (bpos+l[b]))/(v[a]+v[b]);
                        }
                }
        }
        if(adir==bdir){
                if(adir==0){
                        double limit = min((al - apos)/v[a], (bl - bpos)/v[b]);
                        double t = 0.0;
                        if(v[a]!=v[b])
                                t = apos < bpos ? fabs((apos + l[a] - bpos)/(v[a]-v[b])) : fabs((bpos + l[b] - apos)/(v[a]-v[b]));
                        else
                                t = DINF;
                        if(limit<0.000000000001) {
                                if(apos<bpos){
                                        return (bpos - (apos+l[a]))/(v[a]+v[b]); 
                                }else{
                                        return (apos - (bpos+l[b]))/(v[a]+v[b]);
                                }
                        }
                        if(limit < t){
                                return limit + get(time+limit, a, b);
                        }else{
                                return t;
                        }
                }else {
                        double limit = min(apos/v[a], bpos/v[b]);
                        double t = 0.0;
                        if(v[a]!=v[b])
                                t = bpos < apos ? fabs((bpos + l[b] - apos)/(v[a]-v[b])) : fabs((apos + l[a] - bpos)/(v[a]-v[b]));
                        else
                                t = DINF;
                        if(limit<0.000000000001) {
                                if(apos>bpos){
                                        return (bpos - (apos+l[a]))/(v[a]+v[b]); 
                                }else{
                                        return (apos - (bpos+l[b]))/(v[a]+v[b]);
                                }
                        }
                        if(limit < t){
                                return limit + get(time+limit, a, b);
                        }else{
                                return t;
                        }
                }
        }
        return DINF;
}
double get_dp(int idx)
{
       
        if(idx==0) return 0;
        if(idx<0) return DINF;
        double& ret = cache[idx];
        if(ret > -0.5) return ret;
        
        ret = DINF;
        for(int i=1;i<=K;++i){
                double t = get_dp(idx-i);
                //printf("%d %d %f\n",idx-i,idx,get(t,idx-i,idx));
                ret = min(ret, t + get(t,idx-i,idx));
        }
        return ret;
}
int main()
{
        scanf("%d%d%d",&N,&L,&K);
        for(int i=0;i<N;++i){
                scanf("%d%d%d",&l[i],&d[i],&v[i]);
        }
        for(int i=0;i<N;++i){
                cache[i] = -1.0;
        }
        //for(int i=0;i<N;++i)printf("%.5f\n",get_dp(i));
        printf("%.5f\n",get_dp(N-1));
}

