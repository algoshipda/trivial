#include <bits/stdc++.h>
using namespace std;
int d[100][2];
char s[1005];
set<int> x;
int main()
{
	int n;
	d['E'][0] = 1;
	d['W'][0] = -1;
	d['N'][1] = 1;
	d['S'][1] = -1;
	scanf("%d%s",&n,s);
	x.insert(0);
	int cx=0;
	int cy=0;
	for(int i=0;s[i];++i){
		cx+=d[s[i]][0];
		cy+=d[s[i]][1];
		x.insert(cx*20000+cy);
	}
	printf("%d\n",(int)x.size());
}
