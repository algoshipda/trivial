#include <cstdio>
#include <algorithm>
#include <vector>
#define pb(A) push_back((A))
using namespace std;
int n,k;
int num[205];
vector<int> s;
int main()
{
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;++i)
                scanf("%d",&num[i]);
        
        s.pb(num[0]);
        for(int i=1;i<n;++i){
                if(s[s.size()-1]!=num[i])
                        s.pb(num[i]);
        }
        
        for(int i=0;i<(int)s.size();++i){
                printf("%d\n",s[i]);
        }
}
