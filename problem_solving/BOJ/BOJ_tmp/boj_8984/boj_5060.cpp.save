#include <cstdio>
#include <algorithm>
using namespace std;
const double INF = 98765432123456789.0;
int h,c;
int pos[205];
double cache[205][205];
double err_cache[205][205];
double error(int left, int right)
{
        double& ret = err_cache[left][right];
        if(ret >= -0.5)return ret;
        ret = 0.0;
        for(int i = left+1;i<right;++i){
                ret += abs((pos[left] + (double)(pos[right]-pos[left])*(i-left)/(right-left)) - pos[i]);
        }
        return ret;
}
double get_dp(int idx, int rem)
{
        if(rem == 2){
                if(idx < h-1)
                        return error(idx,h-1);
                else 
                        return INF;
        }
        if(idx>=h) return INF;
        
        double& ret = cache[idx][rem];
        if(ret>=-0.5)return ret;
        ret = INF;
        for(int i=idx+1;i<h-1;++i){
                ret = min(ret, error(idx,i) + get_dp(i, rem-1));
        }
        return ret;
}
int main()
{
        int t;
        for(scanf("%d",&t);t;--t){
                scanf("%d%d",&h,&c);
                for(int i=0;i<h;++i){
                        for(int j=0;j<h;++j){
                                cache[i][j] = -1.0;
                                err_cache[i][j] = -1.0;
                        }
                }
                for(int i=0;i<h;++i)scanf("%d",&pos[i]);
                printf("%.4f\n",get_dp(0,c)/h);
        }

}
