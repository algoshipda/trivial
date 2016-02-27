#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Line{
        int x;
        int y;
};

bool cmp(Line a, Line b)
{
        if(a.x!=b.x)return a.x<b.x;
        return a.y<b.y;
}

int n, l;
Line line[100005];
vector<int> X;
vector<int> Y;
long long dp[100005][2];

int main()
{
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;++i){
                scanf("%d%d",&line[i].x,&line[i].y);
                X.push_back(line[i].x);
                Y.push_back(line[i].y);
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        X.erase(unique(X.begin(),X.end()),X.end());
        Y.erase(unique(Y.begin(),Y.end()).Y.end());
        sort(line,line + n,cmp);
        long long ans = 0;   
        for(int i=0;i<n;++i){
                int xidx = lower_bound(line_set.begin(),line_set.end(),line[i].x) - line_set.begin();
                int yidx = lower_bound(line_set.begin(),line_set.end(),line[i].y) - line_set.begin();
                int length = abs(line[i].x - line[i].y) + l;
                long long dpu = dp[xidx][0];
                long long dpd = dp[yidx][1];    
                dp[xidx][0] = max(dpu, dpd + length);
                dp[yidx][1] = max(dpd, dpu + length);
                ans = max(ans, max(dp[xidx][0], dp[yidx][1]));
        }      
        printf("%lld\n",ans);
}
