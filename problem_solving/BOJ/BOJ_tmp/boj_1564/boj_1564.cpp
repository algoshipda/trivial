#include <cstdio>

int main()
{
        int n;
        long long mod = 100000000000000L;
        long long k = 1;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
                k*=i;
                while(k%10==0){
                        k/=10;
                }
                k = k%mod;
                printf("%lld\n",k%10);
        }
        printf("%lld\n",k%10);
}
