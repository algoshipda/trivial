#include <bits/stdc++.h>
using namespace std;
char card[9][5];
map<vector<int>, double> dp;
double rec(vector<int> a)
{
	bool valid=true;
	for(int i=0;i<9;++i){
		if(a[i]<0) return 0.0;
		if(a[i]>0)valid=false;
	}
	if(valid)return 1.0;
	if(dp.count(a))return dp[a];
	double ret=0.0;
	int cnt=0;
	for(int i=0;i<9;++i){
		for(int j=i+1;j<9;++j){
			if(a[i]>0 && a[j]>0 && card[i][a[i]]==card[j][a[j]])++cnt;
		}
	}
	for(int i=0;i<9;++i){
		for(int j=i+1;j<9;++j){
			if(a[i]>0 && a[j]>0 && card[i][a[i]]==card[j][a[j]]){
				a[i]--;
				a[j]--;
				ret+=rec(a)/cnt;
				a[i]++;
				a[j]++;
			}
		}
	}
	return dp[a]=ret;
}
int main()
{
	for(int i=0;i<9;++i){
		for(int j=1;j<=4;++j){
			char x;
			scanf("%c %c ",&card[i][j],&x);
		}
	}
	vector<int> a(9,4);
	printf("%.6f\n", rec(a));
}
