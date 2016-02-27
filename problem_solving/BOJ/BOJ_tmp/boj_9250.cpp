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


struct Node{
    int t;
    Node* f;
    Node* nxt[26];
    Node():t(0),f(0){
        for(int i=0;i<26;++i)nxt[i]=0;
    }
};

int K;
Node nodes[1000005];

Node* new_node()
{
    Node* ret = &nodes[K++];
    ret->f = 0;
    ret->t = 0;
    for(int i=0;i<26;++i)ret->nxt[i]=0;
    return ret;
}
int N,M;
char S[10005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	Node* root = new_node();
	for(i=0;i<N;++i){
        scanf("%s",S);
        Node* now = root;
        for(j=0;S[j];++j){
            int c = S[j]-'a';
            if(!now->nxt[c])now->nxt[c] = new_node();
            now = now->nxt[c];
        }
        now->t = 1;
    }
    queue<Node*> q;
    root->f = root;
    for(i=0;i<26;++i){
        if(root->nxt[i]){
            root->nxt[i]->f = root;
            q.push(root->nxt[i]);
        }
    }
    
    while(!q.empty()){
        Node* now = q.front();
        q.pop();
        for(i=0;i<26;++i){
            if(!now->nxt[i])continue;
            Node* tmp = now->f;
            while(tmp!=root && !tmp->nxt[i])tmp = tmp->f;
            if(tmp->nxt[i])tmp = tmp->nxt[i];
            if(tmp->t)now->nxt[i]->t=1;
            now->nxt[i]->f = tmp;  
            q.push(now->nxt[i]);          
        }
    }
    scanf("%d",&M);
    for(i=0;i<M;++i){
        scanf("%s",S);
        Node* now = root;
        bool ans =false;
        for(j=0;S[j];++j){
            int c = S[j]-'a';
            while(now!=root && !now->nxt[c])now = now->f;
            if(now->nxt[c])now = now->nxt[c];
            if(now->t){
                ans = true;
                //now = now->f;
            }
        }
        puts(ans?"YES":"NO");
    }
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

