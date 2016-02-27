#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int num[1005];
int main()
{
        scanf("%d",&n);
        for(int i=0;i<n;++i)
                scanf("%d",&num[i]);
        
        sort(num,num+n);
        
        int sum=0;
        for(int i=0;i<n;++i){
                if(sum+1<num[i]){
                        break;
                }
                sum+=num[i];
        }
        printf("%d\n",sum+1);
        return 0;
}
