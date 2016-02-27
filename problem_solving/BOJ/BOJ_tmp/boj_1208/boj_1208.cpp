#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n,s,m;
unordered_map<int,int> left;
unordered_map<int,int> right;
vector<int> v;

void lmake(int sum, int i, bool choosen)
{
        if (i==m) {
                if (choosen) {
                        if(!left.count(sum))
                                left[sum]=1;
                        else
                                ++left[sum];
                }
                return;
        }

        lmake(sum+v[i+1], i+1, 1);
        lmake(sum, i+1, choosen);
}

void rmake(int sum, int i, bool choosen)
{
        if (i==n-1) {
                if (choosen) {
                        if(!right.count(sum))
                                right[sum]=1;
                        else
                                ++right[sum];
                }
                return;
        }

        rmake(sum+v[i+1], i+1, 1);
        rmake(sum, i+1, choosen);
}

int main()
{
        int i;
        scanf("%d%d",&n,&s);
        v.resize(n);
        for (i=0; i<n; ++i)
                scanf("%d",&v[i]);
        m = n/2;
        lmake(0,-1,0);
        rmake(0,m,0);
        long long cnt = 0;
        for (unordered_map<int,int>::iterator it = left.begin(); it != left.end(); ++it) {
                cnt += it->first==s?it->second:0;
                cnt += right.count(s-it->first)?(long long)it->second * right[s-it->first]:0;
        }
        for (unordered_map<int,int>::iterator it = right.begin(); it != right.end(); ++it)
                cnt += it->first==s?it->second:0;

        printf("%lld\n",cnt);



}
