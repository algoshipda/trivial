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

int N;
string s;

void dfs(string& k, vector<bool>& used, int cnt)
{
    if(cnt == (int)s.size()){
        printf("%s\n",k.c_str());
        return;
    }
    vector<bool> visited(26,0);
    for(int i=0;i<(int)s.size();++i){
        if(used[i])continue;
        if(visited[s[i]-'a'])continue;
        used[i] = 1;
        k.pb(s[i]);
        visited[s[i]-'a']=1;
        dfs(k,used,cnt+1);
        k.pop_back();
        used[i] = 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        cin>>s;
        sort(s.begin(),s.end());
        string k;
        vector<bool> used(s.size(),0);
        vector<bool> visited(26,0);
        for(int i=0;i<(int)s.size();++i){
            if(visited[s[i]-'a'])continue;
            visited[s[i]-'a']=1;
            k.pb(s[i]);
            used[i] = 1;
            dfs(k,used,1);
            used[i] = 0;
            k.pop_back();
        }
    }

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}

