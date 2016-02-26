#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MN = 1e6 + 10;
int pos[MN];
char ch[MN];
int main()
{
    string a, b;
    cin >> a >> b;
    int top = 0, matched = 0;
    vector<int> pi(b.size(), 0);
    for(int i = 1 ; i < b.size(); ++i){
        while(matched > 0 && b[i] != b[matched]) matched = pi[matched - 1];
        if(b[i] == b[matched]) ++matched;
        pi[i] = matched;
    }
    matched = 0;
    for(int i = 0; i < a.size(); ++i){
        while(matched > 0 && a[i] != b[matched]) matched = pi[matched - 1];
        if(a[i] == b[matched]) ++matched;
        ch[++top] = a[i];
        pos[top] = matched;
        if(matched == b.size()){
            top -= b.size();
            matched = pos[top];
        }
    }
    ch[top + 1] = 0;
    cout << (ch + 1) << '\n';
}
