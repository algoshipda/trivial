#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

string a;
string b;
int lcs[4505][2205];
int ch[2205];
int st[2205];
int dp[2205];
int cut1[2205];
int cut2[2205];
int n,m;

int rec(int x)
{
	if(x==m)return 0;
	if(x>m)return INF;
	int&ret = dp[x];
	if(ret!=-1)return ret;
	ret=INF;
	cut1[x]=st[x];
	for(int i=x+1;i<=x+ch[x];++i){
		int c=1+rec(i);
		if(ret>c){
			ret=c;
			cut2[x]=st[x]+i-x-1;
		}
	}
	return ret;
}
int main()
{
	cin>>a;
	cin>>b;
	a+="*"+string(a.rbegin(),a.rend());
	for(int i=(int)a.size()-1;i>=0;--i){
		for(int j=(int)b.size()-1;j>=0;--j){
			if(a[i]==b[j]){
				lcs[i][j]=1+lcs[i+1][j+1];
			}
			if(ch[j]<lcs[i][j]){
				ch[j]=lcs[i][j];
				st[j]=i;
			}
		}
	}
	n=a.size();
	m=b.size();
	memset(dp,-1,sizeof(dp));
	int ans=rec(0);
	if(ans>=5000){
		puts("-1");
		return 0;
	}
	printf("%d\n",ans);
	int cur=0;
	int h=n/2;
	while(cur<m){
		rec(cur);
		int c1=cut1[cur];
		int c2=cut2[cur];
		int l=c2-c1+1;
		if(c1>h){
			c1-=h;
			c2-=h;
			c1=h-c1;
			c2=h-c2;
			printf("%d %d\n",c1+1,c2+1);
		}else{
			printf("%d %d\n",c1+1,c2+1);
		}
		cur+=l;
	}
}
