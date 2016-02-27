#include <bits/stdc++.h>
using namespace std;

char str[500005];

void suffix_array()
{
	int M = 26;
	int N = strlen(str);
	vector<int> cnt(max(M,N),0);
	vector<int> x(N,0);
	vector<int> y(N,0);
	vector<int> SA(N,0);
	
	int i,j,k;
	for(i=0;i<N;++i)x[i] = str[i]-'a';
	for(i=0;i<N;++i)cnt[x[i]]++;
	for(i=1;i<M;++i)cnt[i]+=cnt[i-1];
	for(i=N-1;i>=0;--i)SA[--cnt[x[i]]] = i;
	
	for(int len=1,p=0;p<N-1;M=p,len<<=1){
		p=0;
		for(i=N-len;i<N;++i)y[p++] = i;
		for(i=0;i<N;++i)if(SA[i]>len-1)y[p++]=SA[i]-len;
		for(i=0;i<M;++i)cnt[i]=0;
		for(i=0;i<N;++i)cnt[x[i]]++;
		for(i=1;i<M;++i)cnt[i]+=cnt[i-1];
		for(i=N-1;i>=0;--i)SA[--cnt[x[y[i]]]]=y[i];
		swap(x,y);
		
		p=0;
		x[SA[0]]=0;
		for(int i=0;i<N-1;++i){
			x[SA[i+1]]= SA[i]+len<N && SA[i+1]+len<N &&
				y[SA[i]+len] == y[SA[i+1]+len] ? p : ++p;
		}
	}
	for(i=0;i<N;++i)printf("%d %c %d\n",i,str[SA[i]],SA[i]+1);
}
int main()
{
	freopen("input.txt","r",stdin);
	scanf("%s",str);
	suffix_array();
	fclose(stdin);
}	
