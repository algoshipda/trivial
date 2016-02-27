#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <stack>


#define pb(a) push_back(a)
#define sz(a) ((int)a.size())

using namespace std;
const int INF = 987654321;
const long long LINF = 9876543212345;
const double DINF = 987654321.0;
int h,c;
int pos[205];
double cache[205][205];
double error[205][205];
double bogan(int i, int j, int k)
{
        return pos[i] + (double)(pos[j]-pos[i])*(k-i)/(j-i);
}
double getError(int left, int right)
{
        double& ret = error[left][right];
        if(ret>-0.5) return ret;
        ret = 0.0;
        for(int k=left+1;k<right;++k){
                ret += fabs(pos[k]-bogan(left,right,k));
        }
        return ret;
}
double get_dp(int idx, int remain)
{       
        if(idx==h)return DINF;
        if(remain==2){
                return getError(idx,h-1);
        }
        double& ret = cache[idx][remain];
        if(ret>-0.5)return ret;
        ret = DINF;
        for(int i=idx+1;i<h-1;++i){
                ret = min(ret , getError(idx,i) + get_dp(i,remain-1));
        }
        return ret;
}
int main()
{
        int t;
        for(scanf("%d",&t);t;--t){
                scanf("%d%d",&h,&c);
                for(int i=0;i<h;++i){
                        scanf("%d",&pos[i]);
                        for(int j=0;j<h;++j){
                                cache[i][j] = -1.0;
                        }
                }
                for(int i=0;i<h;++i){
                        for(int j=0;j<h;++j){
                                error[i][j] = -1.0;
                        }
                }
                printf("%.4f\n",get_dp(0, c)/h);
        }


}
