#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n;  
int C[500005];
int idx[1000005];
class Fenwick{
        vector<int> tree;
        int sz;
public:
        Fenwick(){
                sz = n+2;
                tree.resize(n+2);
        }
        
        int set(int idx, int val)
        {
                int i = idx;
                int ret = 0;
                while(i>0){
                        ret += tree[i];
                        i -= (i&-i);
                }
                
                i = idx;
                while(i<=sz){
                        tree[i] += val;
                        i += (i&-i);
                }
                return ret;
        }
};
int main()
{
        scanf("%d",&n);
        Fenwick f;
        long long ans = 0;
        for(int i=1;i<=n;++i){
                int x;
                scanf("%d",&x);
                idx[x] = i;
        }
        for(int i=1;i<=n;++i){
                int x;
                scanf("%d",&x);
                C[i] = idx[x];
        }
        for(int i=n;i>=1;--i){
                ans += f.set(C[i],1);
        }
        printf("%lld\n",ans);
}
