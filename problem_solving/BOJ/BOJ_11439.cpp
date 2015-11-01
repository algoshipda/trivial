#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
bool np[4000005];
int n,k,m;
vector<int> primes;
int pow(int n, int k)
{
	if(k==0)return 1;
	if(k&1)return (lld)n*pow(n,k-1)%m;
	int half=pow(n,k>>1);
	return (lld)half*half%m;
}
vector<int> f(int x)
{
	vector<int> ret;
	for(int i=0;i<primes.size() && primes[i]<=x;++i){
		ret.push_back(0);
		lld y=primes[i];
		while(y<=x){
			ret.back()+=x/y;
			y*=primes[i];
		}
	}
	return ret;
}
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=2;i<=n;++i){
        if(!np[i]){
            primes.push_back(i);
            for(lld j=(lld)i*i;j<=n;j+=i)np[j]=1;
        }
    }
    vector<int> f1=f(n);
    vector<int> f2=f(n-k);
    vector<int> f3=f(k);
    f2.resize(f1.size());
    f3.resize(f1.size());
    lld ans=1;
    for(int i=0;i<f1.size();++i){
    	f1[i]-=f2[i]+f3[i];
    	ans=ans*pow(primes[i],f1[i])%m;
    }
    printf("%lld\n",ans);
}