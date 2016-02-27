#include <cstdio>
#include <algorithm>
using namespace std;
int num[100005];
int n,k;
int main()
{
        int ans = 0,sum=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)scanf("%d",&num[i]);
        for(int i=0;i<k;++i)
                sum += num[i];
        ans = sum;
        for(int i=0;i+k<n;++i){
                sum -= num[i];
                sum += num[i+k];
                ans = max(sum,ans);
        }
        printf("%d\n",ans);
}
