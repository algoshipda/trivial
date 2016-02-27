#include <bits/stdc++.h>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

int C[130];
struct Node{
    int t;
    Node* f;
    Node* nxt[4];
    Node():t(0),f(0){for(int i=0;i<4;++i)nxt[i]=0;}
};

int K;
Node nodes[1000005];
Node* new_node()
{
    Node* ret = &nodes[K++];
    ret->f=0;
    ret->t=0;
    for(int i=0;i<4;++i)ret->nxt[i]=0;
    return ret;
}


int T,N,M;
char A[1000005];
char B[105];
string S;
int main()
{
    C['C']=1;
    C['G']=2;
    C['T']=3;
    
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        scanf("%s",A);
        scanf("%s",B);
        S=B;
        
        int i,j,k;
        vector<string> v;
        for(i=0;i<M;++i){
            for(j=1;i+j<=M;++j){
                string s = S.substr(i,j);
                reverse(s.begin(),s.end());
                v.pb(S.substr(0,i)+s+S.substr(i+j,M-j));
            }
        }
        sort(all(v));
        v.erase(unique(all(v)),v.end());
        //for(i=0;i<sz(v);++i)printf("%s\n",v[i].c_str());
        Node* root = new_node();
        for(i=0;i<sz(v);++i){
            Node* now = root;
            for(j=0;j<sz(v[i]);++j){
                int c = C[(int)v[i][j]];
                if(!now->nxt[c])now->nxt[c] = new_node();
                now = now->nxt[c];
            }
            now->t = 1;
        }
        
        queue<Node*> q;
        root->f = root;
        for(i=0;i<4;++i){
            if(root->nxt[i]){
                root->nxt[i]->f = root;
                q.push(root->nxt[i]);
            }
        }
        
        while(!q.empty()){
            Node* now = q.front();
            q.pop();
            for(i=0;i<4;++i){
                if(!now->nxt[i])continue;
                //calc failure function
                Node* tmp = now->f;
                while(tmp != root && !tmp->nxt[i])
                    tmp = tmp->f;
                if(tmp->nxt[i])tmp=tmp->nxt[i];
                if(tmp->t)now->nxt[i]->t = 1;
                now->nxt[i]->f = tmp;
                q.push(now->nxt[i]);
            }
        }
        
        //aho-corasick
        Node* now = root;
        int ans = 0;
        for(i=0;i<N;++i){
            int c = C[(int)A[i]];
            while(now != root && !now->nxt[c])now = now->f;
            if(now->nxt[c])now = now->nxt[c];
            if(now->t)++ans,now = now->f;
        }
        printf("%d\n",ans);
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

