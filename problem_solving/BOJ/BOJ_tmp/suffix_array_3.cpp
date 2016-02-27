#include <bits/stdc++.h>

using namespace std;


char str[500005];

int x[500005];
int y[500005];
int cnt[500005];
int sa[500005];
void suffix_array()
{
    int M = 26;
    int N = strlen(str);
    int i,j,k;
    for(i=0;i<N;++i)x[i]=str[i]-'a';
    for(i=0;i<N;++i)cnt[x[i]]++;
    for(i=1;i<M;++i)cnt[i]+=cnt[i-1];
    for(i=N-1;i>=0;--i)sa[--cnt[x[i]]] = i;
    
    for(int len=1,p=0;p<N-1;len<<=1){
        p=0;
        for(i=N-len;i<N;++i)y[p++]=i;
        for(i=0;i<N;++i) if(sa[i]>len-1)y[p++] = sa[i]-len;
        for(i=0;i<M;++i)cnt[i]=0;
        for(i=0;i<N;++i)cnt[x[i]]++;
        for(i=1;i<M;++i)cnt[i]+=cnt[i-1];
        for(i=N-1;i>=0;--i)sa[--cnt[x[y[i]]]] = y[i];
        
        swap(x,y);
        p=0;
        x[sa[0]]=0;
        for(i=0;i<N-1;++i){
            x[sa[i+1]] = sa[i]+len<N && sa[i+1]+len<N && y[sa[i]] == y[sa[i+1]] &&
                            y[sa[i]+len] == y[sa[i+1]+len]?p:++p;
        }
        M=p;
    }
    for(i=0;i<N;++i)printf("%d %c %d\n",i,str[sa[i]],sa[i]+1);
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
    scanf("%s",str);
    suffix_array();


#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif

}
