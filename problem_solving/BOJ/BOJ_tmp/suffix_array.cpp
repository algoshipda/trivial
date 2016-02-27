#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int x[500002];
int y[500002];
vector<int> getSuffixArray(const string& H){
    int n = H.size();
    int m = 26;
    vector<int> cnt(max(26,n)+1);
    vector<int> ret(n,0);
    for(int i=0;i<n;++i)++cnt[H[i]-'a'];
    for(int i=1;i<=26;++i)cnt[i] += cnt[i-1];
    for(int i=n-1;i>=0;--i)ret[--cnt[H[i]-'a']] = i;
    for(int i=0;i<n;++i) x[i] = H[i]-'a';
    for(int len = 1,p=0;p<n-1;len*=2){
        p=0;
        for(int i=0;i<=m;++i)cnt[i] = 0;
        for(int i=n-len;i<n;++i) y[p++] = i;
        for(int i=0;i<n;++i) if(ret[i]>len-1) y[p++] = ret[i]-len;
        for(int i=0;i<n;++i) ++cnt[x[i]];
        for(int i=1;i<=m;++i) cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;--i) ret[--cnt[x[y[i]]]] = y[i];
        swap(x,y); x[ret[0]] = 0; p=0;
        for(int i=0;i<n-1;++i)
            x[ret[i+1]] = ret[i]+len<n && ret[i+1]+len<n && y[ret[i]]==y[ret[i+1]] && y[ret[i]+len] == y[ret[i+1]+len]?p:++p;
        m=p;
    }
    return ret;
}

vector<int> getLCP(const vector<int>& sf,const string& s){
    int l = 0;
    int n = sf.size();
    vector<int> inv(n,0);
    vector<int> lcp(n,0);
    for(int i=0;i<n;++i)inv[sf[i]] = i;
    for(int i=0;i<n;++i){
        int k = inv[i];
        int j = k?sf[k-1]:0;
        while(s[i+l]==s[j+l])++l;
        lcp[k] = l;
        if(l)--l;
    }
    return lcp;
}
int main(){
    string H;
    cin>>H;
    vector<int> sf = getSuffixArray(H);
    vector<int> lcp = getLCP(sf,H);
    int sz = sf.size();
    for(int i=0;i<sz;++i)cout<<sf[i]+1<<" ";
    cout<<endl;
    cout<<"x ";
    for(int i=1;i<sz;++i)cout<<lcp[i]<<" ";
    cout<<endl;
}
