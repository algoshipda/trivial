<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int main()
{
    lld x1,y1,x2,y2,x3,y3;
    scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
    lld ax = x2 - x1;
    lld bx = x3 - x1;
    lld ay = y2 - y1;
    lld by = y3 - y1;
    lld k = ax * by - ay * bx;
    if(k)k/=abs(k);
    printf("%lld\n",k);
}
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int main()
{
    lld x1,y1,x2,y2,x3,y3;
    scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
    lld ax = x2 - x1;
    lld bx = x3 - x1;
    lld ay = y2 - y1;
    lld by = y3 - y1;
    lld k = ax * by - ay * bx;
    if(k)k/=abs(k);
    printf("%lld\n",k);
}
>>>>>>> 5b18d34fd3c47d6b2c01f29aa6d9f163f2723a0d
