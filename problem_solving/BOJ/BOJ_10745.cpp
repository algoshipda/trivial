#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

const int MN = 1e5 + 10;
struct Node
{
    int t;
    Node* f;
    Node* nxt[26];
	Node* go[26];
    Node()
	{
        t = 0;
        f = 0;
        for(int i = 0; i < 26; ++i) nxt[i] = go[i] = 0;
    }
	~Node()
	{
		for(int i = 0; i < 26; ++i){
			if(nxt[i]){
				delete nxt[i];
				nxt[i] = 0;
			}
			if(go[i]){
				delete go[i];
				go[i] = 0;
			}
		}
	}
};

Node* pos[MN];
char ch[MN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    int n;
    cin >> a >> n;

    vector<string> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    Node* root = new Node();
    for(int i = 0; i < n; ++i){
        Node* cur = root;
        string& b = v[i];
        for(int j = 0; j < b.size(); ++j){
            int c = b[j] - 'a';
            if(!cur->nxt[c]) cur->nxt[c] = new Node();
            cur = cur->nxt[c];
        }
        cur->t = i + 1;
    }
    queue<Node*> q;
    root->f = root;
    for(int i = 0; i < 26; ++i){
        if(root->nxt[i]){
            root->nxt[i]->f = root;
            q.push(root->nxt[i]);
        }
    }

    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        for(int i = 0; i < 26; ++i){
            if(cur->nxt[i]){
                Node* tmp = cur->f;
                while(tmp != root && !tmp->nxt[i]) tmp = tmp->f;
                if(tmp->nxt[i]) tmp = tmp->nxt[i];
                cur->nxt[i]->f = tmp;
                q.push(cur->nxt[i]);
            }
        }
    }

    Node* cur = root;
    int top = 0;
	pos[0] = cur;
    for(int i = 0; i < a.size(); ++i){
        int c = a[i] - 'a';
		if(cur->go[c]){
			cur = cur->go[c];
		}else{
			Node* prv = cur;
			while(cur != root && !cur->nxt[c]) cur = cur->f;
			if(cur->nxt[c]) cur = cur->nxt[c];
			prv->go[c] = cur;
		}

        ch[++top] = a[i];
        pos[top] = cur;
        if(cur->t){
            top -= v[cur->t - 1].size();
            cur = pos[top];
        }
    }
    ch[top + 1] = 0;
    cout << (ch + 1) << '\n';
}
