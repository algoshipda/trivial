#include <bits/stdc++.h>
using namespace std;
char s[1005];
int trie[1000005][26];
int cnt;
int main()
{
    scanf("%s",s);
    for(int i=0;s[i];++i){
        int now=0;
        for(int j=i;s[j];++j){
            int c=s[j]-'a';
            if(!trie[now][c])trie[now][c]=++cnt;
            now=trie[now][c];
        }
    }
    printf("%d\n",cnt);
}
