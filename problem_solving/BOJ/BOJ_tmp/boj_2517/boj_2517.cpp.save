/*현재 자기 위치에서 현재 자기보다 앞서 있는 사람 중 자기 실력보다 못한 사람의 숫자를 세서 빼면 된다.
  입력이 50만이므로 NlgN 알고리즘 필요. 펜윅트리 쓰면 된다. 단, 각각 입력은 정수범위 1,000,000,000 이므로
  그대로 사용해서는 다 담을 수 없다. 따라서 1,000,000,000을 50,0000으로 맵핑시켜야 한다. 일단 입력을 다 받은 다음,
  정렬하고 map으로 실력-키, 인덱스-값으로 해서 만들기로 했다.*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <cassert>
using namespace std;

struct fenwick{
        int tree[500005];
        int size;
        fenwick(){};
        fenwick(int sz){
                memset(tree,0,sizeof(tree));
                size = sz+1;
        }
        
        int sum(int pos){
                ++pos;
                int ret = 0;
                while(pos>0){
                        ret += tree[pos];
                        pos &= (pos-1);
                }
                return ret;
        }
        void add(int pos,int val){
                ++pos;
                while(pos<size){
                        tree[pos] += val;
                        pos += (pos&-pos);
                }
        }
};

int n;
pair<int,int> num[500002];
int mapped[500002];
fenwick fw;
int main(){
        scanf("%d",&n);
        for (int i=0; i<n; ++i){
                scanf("%d",&num[i].first);
                num[i].second = i;
        }
        fw = fenwick(n);
        sort(num,num+n);
        for(int i=0;i<n;++i)
                mapped[num[i].second] = i;
        
        for (int i=0; i<n; ++i) {
                printf("%d\n",i+1-fw.sum(mapped[i]));
                fw.add(mapped[i],1);
        }
        return 0;
}      
