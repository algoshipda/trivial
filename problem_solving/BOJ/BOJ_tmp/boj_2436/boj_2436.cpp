#include <cstdio>
#include <cmath>

int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
}

int flcm(int a, int b){
        return (long long)a*b/gcd(a,b);
}
int main(){
        long long lcm,gcd;
        scanf("%lld%lld",&gcd,&lcm);
        int m = sqrt(lcm*gcd);
        long long a = gcd;
        long long b = lcm;
        for(int i=gcd;i<=m;i+=gcd){
                if(((lcm*gcd)%i)==0){
                        if(a+b>i+lcm*gcd/i){
                                if(flcm(i,lcm*gcd/i)==lcm){
                                        a = i;
                                        b = lcm*gcd/i;
                                }
                        }
                }
        }
        if(a>b){
                long long t = a;
                a = b;
                b = t;
        }
        printf("%lld %lld\n",a,b);
}
