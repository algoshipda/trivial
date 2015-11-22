#include <bits/stdc++.h>
using namespace std;
int n, m, e;
int main()
{
	scanf("%d%d", &n, &m);
	int ans = n / 2 + m / 2;
	if(n % 2 == 0 || m % 2 == 0){
		printf("%d\n", ans);
		return 0;
	}
	scanf("%d", &e);
	for(int i = 0; i < e; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		if(x % 2 && y % 2){
			printf("%d\n", ans + 1);
			return 0;
		}
	}
	printf("%d\n", ans);
}
