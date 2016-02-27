#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
int N;
int cost[1005];



int calc(int n, int prev)
{
	if (n==1 && prev==1) {
		return cost[1];
	}
	if (n==1 && prev==2) {
		return INF;
	}
	if (n==2 && prev==2) {
		return cost[2];
	}
	
	if (prev==1) {
		return calc(n-1, 2) + cost[n];
	}
	if (prev==2) {
		return max(calc(n-2, 2), calc(n-2, 1)) + cost[n];
	}
	return 0;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&cost[i]);
	}
	memset(cost, -1, sizeof(cost));
	printf("%d", max(calc(N, 1), calc(N, 2)));
	return 0;
}
