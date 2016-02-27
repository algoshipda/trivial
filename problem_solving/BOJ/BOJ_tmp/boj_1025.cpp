#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
char num[12][12];
vector<long long> v;
bool isSquare(long long k){
        return binary_search(v.begin(),v.end(),k);
}
int main()
{
        for(int i=0;i<=1000000;++i){
                v.push_back((long long)i*i);
        }
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)scanf("%s",num[i]);
        
        long long sum = -1;
        int z = max(m,n);
        for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                        for(int q=-(n-1);q<n;++q){
                                for(int w=-(m-1);w<m;++w){
                                        long long tmp = -1;
                                        for(int k=0;(k<z && i+q*k<n && j+w*k<m && i+q*k >=0 && j+w*k>=0) || 
                                                (q==0 && w==0 && k<1);++k){
                                                tmp = tmp==-1?0:tmp*10;
                                                tmp += num[i+q*k][j+w*k]-'0';
                                        }
                                        if(isSquare(tmp)){
                                                sum = max(sum,tmp);
                                        }
                                }
                        }
                }
        }
        
        printf("%lld\n",sum);
}
