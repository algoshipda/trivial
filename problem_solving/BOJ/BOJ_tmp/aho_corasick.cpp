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
    //terimal node flag
    int terminal;
    //next node      idx = edge
    Node* next[26];
    Node():terminal(0){
        for(int i=0;i<26;++i)next[i] = 0;
    }
};

int K;
vector<string> str;
Node nodes[10005];

Node* new_node()
{
    Node* ret = &nodes[K++];
    ret->terminal = 0;
    for(int i=0;i<26;++i)ret->next[i] = 0;
    return ret;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    string s;
	while(cin>>s)str.pb(s);
	Node* root = new_node();
	for(int i=0;i<(int)str.size();++i){
        Node* now = root;
        for(int j=0;j<(int)str[i].size();++j){
            int c = str[i][j]-'A';
            if(!now->next[c])now->next[c] = new_node();
            now = now->next[c];
        }
        now->terminal = 1;
	}
	for(int i=0;i<(int)str.size();++i){
        Node* now = root;
        for(int j=0;j<(int)str[i].size();++j){
            int c = str[i][j]-'A';
            printf("%c",c+'A');
            now = now->next[c];
            if(j==(int)str[i].size()-1 && now->terminal){
                printf(" FOUND!!\n");
            }
        }
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

